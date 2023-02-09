#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

#include "Types.h"
#include <System.JSON.hpp>


#pragma package(smart_init)
#pragma link "sgcBase_Classes"
#pragma link "sgcSocket_Classes"
#pragma link "sgcTCP_Classes"
#pragma link "sgcWebSocket"
#pragma link "sgcWebSocket_Classes"
#pragma link "sgcWebSocket_Server"
#pragma resource "*.dfm"


using namespace std;
TForm1 *Form1;


__fastcall TForm1::TForm1(TComponent* Owner)
							: TForm(Owner) {

}


void __fastcall TForm1::Memo1Change(TObject *Sender) {
	if(Memo1->Lines->Count > 6) {
        Memo1->ScrollBars = ssVertical;
    }
}


void __fastcall TForm1::N2Click(TObject *Sender) {
	if(DataModule2->SaveDialog1->Execute()) {
        Memo1->Lines->SaveToFile(DataModule2->SaveDialog1->FileName);
    }
}


void __fastcall TForm1::N3Click(TObject *Sender) {
	if(DataModule2->OpenDialog1->Execute()) {
        Memo1->Lines->LoadFromFile(DataModule2->OpenDialog1->FileName);
    }
}


void __fastcall TForm1::N4Click(TObject *Sender) {
	for(int i = Memo1->Lines->Count; i >= 0; i--) {
		Memo1->Lines->Delete(i);
	}
}


void __fastcall TForm1::FormCreate(TObject *Sender) {
	Log("SYSTEM: Server successfully started. Start logging.");
}


void __fastcall TForm1::Log(String logMessage) {
    Memo1->Lines->Add(logMessage);
}


void __fastcall TForm1::NotifyRoomChangedFullness(String playerGuid,
													roomFullness roomStatus) {
	TJSONObject *notifyRoomChangedFull = new TJSONObject();
	notifyRoomChangedFull->AddPair("method", NOTIFY_ROOM_CHANGED_FULLNESS);
	notifyRoomChangedFull->AddPair("room_is_full", roomStatus == FULL ? true : false);

	String notifyRoomChangedFull_str = notifyRoomChangedFull->ToString();

	sgcWebSocketServer1->WriteData(playerGuid,
		notifyRoomChangedFull_str);

	notifyRoomChangedFull->Free();
}


void __fastcall TForm1::DisconnectPlayerFromRoom(String playerGuid) {
	DataModule2->ADOTable1->First();

	while(!DataModule2->ADOTable1->Eof) {
        int playerNumber = 0;
		gameRoom room = dbContext.MapGameRoom(*DataModule2->ADOTable1->Fields);

		if(room.firstPlayerGuid == playerGuid) {
			playerNumber = 1;
		} else if(room.secondPlayerGuid == playerGuid) {
			playerNumber = 2;
		}

		if(playerNumber) {
            DataModule2->ADOTable1->Edit();
			DataModule2->ADOTable1->Fields->
				FieldByName(playerNumber == 1 ? "GuidFirst" : "GuidSecond")->
				Value="";
			DataModule2->ADOTable1->Fields->
				FieldByName(playerNumber == 1 ? "CodeIsUsedFirst" : "CodeIsUsedSecond")->
				Value=false;
			DataModule2->ADOTable1->Post();

			if(room.codeIsUsedSecond) {
				NotifyRoomChangedFullness(
					playerNumber == 1 ? room.secondPlayerGuid : room.firstPlayerGuid,
					PARTIAL
				);
			}

			break;
        }


		DataModule2->ADOTable1->Next();
	}
}


guestCodeCheckInfo __fastcall TForm1::CheckGuestCode(int reqRoomId,
													int reqPlayerCode,
													String guid) {
	DataModule2->ADOTable1->First();

	guestCodeCheckInfo checkInfo = {
		false,
		false,
		false
	};

	while (!DataModule2->ADOTable1->Eof) {
		int playerNumber = 0;
		gameRoom room = dbContext.MapGameRoom(*DataModule2->ADOTable1->Fields);

		if (reqRoomId == room.roomId) {
			if (reqPlayerCode == room.firstCode) {
				if(!room.codeIsUsedFirst) {
					playerNumber = 1;
                }
			} else if (reqPlayerCode == room.secondCode) {
				if(!room.codeIsUsedSecond) {
                    playerNumber = 2;
				}
			} else {
				return checkInfo;
			}
		}

		if (playerNumber) {
			DataModule2->ADOTable1->Edit();
			DataModule2->ADOTable1->Fields->
				FieldByName(playerNumber == 1 ? "GuidFirst" : "GuidSecond")->
				AsString=guid;
			DataModule2->ADOTable1->Fields->
				FieldByName(playerNumber == 1 ? "CodeIsUsedFirst" : "CodeIsUsedSecond")->
				AsBoolean=true;
			DataModule2->ADOTable1->Post();

			if (room.codeIsUsedFirst) {
				NotifyRoomChangedFullness(room.firstPlayerGuid, FULL);
			} else if (room.codeIsUsedSecond) {
				NotifyRoomChangedFullness(room.secondPlayerGuid, FULL);
			}

			checkInfo = {
				true,
				playerNumber == 1 ? (room.move == 1) : (room.move == 2),
				playerNumber == 1 ? room.codeIsUsedSecond : room.codeIsUsedFirst
			};

			return checkInfo;

        }

		DataModule2->ADOTable1->Next();
	}

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


String TForm1::GetTargetPlayerGuid(String guid) {
	DataModule2->ADOTable1->First();

	while(!DataModule2->ADOTable1->Eof) {
		String targetPlayerGuid;
		gameRoom room = dbContext.MapGameRoom(*DataModule2->ADOTable1->Fields);

		if(room.firstPlayerGuid == guid) {
			targetPlayerGuid = room.secondPlayerGuid;

			return targetPlayerGuid;
		} else if (room.secondPlayerGuid == guid) {
			targetPlayerGuid = room.firstPlayerGuid;

            return targetPlayerGuid;
		}

		DataModule2->ADOTable1->Next();
	}

    return "";
}


void __fastcall TForm1::sgcWebSocketServer1Message(TsgcWSConnection *Connection,
													const UnicodeString Text) {
	String guid = Connection->Guid;
	TJSONObject *request = (TJSONObject*) TJSONObject::ParseJSONValue(Text, 0);

	Log(Text + " - " + guid);

	if(request != NULL) {
		TJSONObject *response = new TJSONObject();

		requests method = static_cast<requests>(
			StrToInt(request->GetValue("method")->Value())
		);

        response->AddPair("method", method);

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
			case MOVE: {
				int row = StrToInt(request->GetValue("row")->Value());
				int col = StrToInt(request->GetValue("col")->Value());

				String targetGuid = GetTargetPlayerGuid(guid);
				if(targetGuid != "") {
					response->AddPair("row", row);
					response->AddPair("col", col);
					response->AddPair("interrogator_guid", guid);

					String response_str = response->ToString();

					sgcWebSocketServer1->WriteData(targetGuid, response_str);

					response->Free();

                    return;
				}

				break;
			}
			case MOVE_ANSWER: {
				String targetGuid = request->GetValue("target_guid")->Value();

				sgcWebSocketServer1->WriteData(targetGuid, Text);

				return;
            }
		}



		String response_str = response->ToString();

		sgcWebSocketServer1->WriteData(guid, response_str);

        response->Free();
	}

	request->Free();
}


void __fastcall TForm1::sgcWebSocketServer1Disconnect(TsgcWSConnection *Connection,
													int Code) {
    String guid = Connection->Guid;
	Log("Player disconnected - " + guid);
	DisconnectPlayerFromRoom(guid);
}


void __fastcall TForm1::sgcWebSocketServer1Connect(TsgcWSConnection *Connection) {
    String guid = Connection->Guid;
    Log("Player connected - " + guid);
}

