//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

#include "Types.h"

#include <System.JSON.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sgcBase_Classes"
#pragma link "sgcSocket_Classes"
#pragma link "sgcTCP_Classes"
#pragma link "sgcWebSocket"
#pragma link "sgcWebSocket_Classes"
#pragma link "sgcWebSocket_Server"
#pragma resource "*.dfm"
TForm1 *Form1;

using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1Change(TObject *Sender)
{
	if(Memo1->Lines->Count > 6) {
        Memo1->ScrollBars = ssVertical;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
	if(DataModule2->SaveDialog1->Execute()) {
        Memo1->Lines->SaveToFile(DataModule2->SaveDialog1->FileName);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
	if(DataModule2->OpenDialog1->Execute()) {
        Memo1->Lines->LoadFromFile(DataModule2->OpenDialog1->FileName);
    }
}

void __fastcall TForm1::Log(String logMessage) {
    Memo1->Lines->Add(logMessage);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
	for(int i = Memo1->Lines->Count; i >= 0; i--) {
		Memo1->Lines->Delete(i);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Log("SYSTEM: Server successfully started. Start logging.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisconnectPlayerFromRoom(String playerGuid) {
	DataModule2->ADOTable1->First();
	while(!DataModule2->ADOTable1->Eof) {
		gameRoom room = dbContext.MapGameRoom(*DataModule2->ADOTable1->Fields);

		if(room.firstPlayerGuid == playerGuid) {
			DataModule2->ADOTable1->Edit();
			DataModule2->ADOTable1->Fields->
				FieldByName("GuidFirst")->Value="";
			DataModule2->ADOTable1->Fields->
				FieldByName("CodeIsUsedFirst")->Value=false;
			DataModule2->ADOTable1->Post();

			if(room.codeIsUsedSecond) {
				NotifyRoomChangedFullness(room.secondPlayerGuid, PARTIAL);
			}

			break;
		} else if(room.secondPlayerGuid == playerGuid) {
			DataModule2->ADOTable1->Edit();
			DataModule2->ADOTable1->Fields->
				FieldByName("GuidSecond")->Value="";
			DataModule2->ADOTable1->Fields->
				FieldByName("CodeIsUsedSecond")->Value=false;
			DataModule2->ADOTable1->Post();

			if(room.codeIsUsedFirst) {
				NotifyRoomChangedFullness(room.firstPlayerGuid, PARTIAL);
			}

			return;
		}


		DataModule2->ADOTable1->Next();

	}
}


void __fastcall TForm1::NotifyRoomChangedFullness(String playerGuid, roomFullness roomStatus) {
    TJSONObject *notifyGameChengedFullness = new TJSONObject();
	notifyGameChengedFullness->AddPair("method", NOTIFY_ROOM_CHANGED_FULLNESS);
	notifyGameChengedFullness->AddPair("room_is_full", roomStatus == FULL ? true : false);

	String notifyGameChengedFullness_str = notifyGameChengedFullness->ToString();

	sgcWebSocketServer1->WriteData(playerGuid,
		notifyGameChengedFullness_str);

	notifyGameChengedFullness->Free();
}


guestCodeCheckInfo __fastcall TForm1::CheckGuestCode(int reqRoomId, int reqPlayerCode, String guid) {
	DataModule2->ADOTable1->First();

	guestCodeCheckInfo checkInfo;

	while (!DataModule2->ADOTable1->Eof) {
		gameRoom room = dbContext.MapGameRoom(*DataModule2->ADOTable1->Fields);

		if(reqRoomId == room.roomId) {
			if (reqPlayerCode == room.firstCode) {
				if(!room.codeIsUsedFirst) {
					DataModule2->ADOTable1->Edit();
					DataModule2->ADOTable1->Fields->
						FieldByName("GuidFirst")->
						AsString=guid;
					DataModule2->ADOTable1->Fields->
						FieldByName("CodeIsUsedFirst")->
						AsBoolean=true;
					DataModule2->ADOTable1->Post();

					if(room.codeIsUsedSecond) {
						NotifyRoomChangedFullness(room.secondPlayerGuid, FULL);
					}

					checkInfo = {
						true,
						room.move == 1,
						room.codeIsUsedSecond
					};

					return checkInfo;
				}
			} else if (reqPlayerCode == room.secondCode) {
				if(!room.codeIsUsedSecond) {
					DataModule2->ADOTable1->Edit();
					DataModule2->ADOTable1->Fields->
						FieldByName("GuidSecond")->
						AsString=guid;
					DataModule2->ADOTable1->Fields->
						FieldByName("CodeIsUsedSecond")->
						AsBoolean=true;
					DataModule2->ADOTable1->Post();

					if(room.codeIsUsedFirst) {
						NotifyRoomChangedFullness(room.firstPlayerGuid, FULL);
					}

                    checkInfo = {
						true,
						room.move == 2,
						room.codeIsUsedFirst
					};

					return checkInfo;
				}
			} else {
                checkInfo = {
					false,
					false,
					false
				};

				return checkInfo;
			}
		}

		DataModule2->ADOTable1->Next();
	}

    checkInfo = {
		false,
		false,
		false
	};

	return checkInfo;
}

gameRoomInfo TForm1::GenerateRoom() {
    srand(time(NULL));

	gameRoomInfo roomInfo = {
		-1,
		rand()%100000,
        rand()%100000
	};

	DataModule2->ADOTable1->Insert();
	DataModule2->ADOTable1->Fields->Fields[1]->Value=roomInfo.firstCode;
	DataModule2->ADOTable1->Fields->Fields[2]->Value=roomInfo.secondCode;

	DataModule2->ADOTable1->Fields->Fields[3]->Value=false;
	DataModule2->ADOTable1->Fields->Fields[4]->Value=false;

	DataModule2->ADOTable1->Fields->Fields[5]->Value="";
	DataModule2->ADOTable1->Fields->Fields[6]->Value="";
    DataModule2->ADOTable1->Fields->Fields[7]->Value=1;
	DataModule2->ADOTable1->Post();

	DataModule2->ADOTable1->Last();
    roomInfo.roomId = DataModule2->ADOTable1->Fields->FieldByName("RoomId")->AsInteger;

    return roomInfo;
}

void __fastcall TForm1::sgcWebSocketServer1Message(TsgcWSConnection *Connection, const UnicodeString Text)
{
	String guid = Connection->Guid;
	Log(Text + " - " + guid);

	TJSONObject *request = (TJSONObject*) TJSONObject::ParseJSONValue(Text, 0);
	if(request != NULL) {
		TJSONObject *response = new TJSONObject();

		requests method = static_cast<requests>(
			StrToInt(request->GetValue("method")->Value())
		);

		switch(method) {
			case CHECK_GUEST_CODE: {
				DisconnectPlayerFromRoom(guid);

				int roomId = StrToInt(request->GetValue("room_id")->Value());
				int playerCode = StrToInt(request->GetValue("player_code")->Value());

				guestCodeCheckInfo checkResult = CheckGuestCode(roomId, playerCode, guid);
				bool codeStatus = checkResult.codeIsValid;
				bool isMyMove = checkResult.moveIsMyne;
				bool roomIsFull = checkResult.roomIsFull;

				response->AddPair("code_status", codeStatus);
				response->AddPair("my_move", isMyMove);
                response->AddPair("room_is_full", roomIsFull);

                break;
			}
			case GENERATE_ROOM: {
				gameRoomInfo roomInfo = GenerateRoom();

				response->AddPair("roomId", roomInfo.roomId);
				response->AddPair("firstCode", roomInfo.firstCode);
				response->AddPair("secondCode", roomInfo.secondCode);

				break;
            }
		}

        response->AddPair("method", method);

		String response_str = response->ToString();

		sgcWebSocketServer1->WriteData(guid, response_str);
	}

	request->Free();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::sgcWebSocketServer1Disconnect(TsgcWSConnection *Connection,
          int Code)
{
    String guid = Connection->Guid;
	Log("Player disconnected - " + guid);
	DisconnectPlayerFromRoom(guid);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sgcWebSocketServer1Connect(TsgcWSConnection *Connection)
{
    String guid = Connection->Guid;
    Log("Player connected - " + guid);
}
//---------------------------------------------------------------------------

