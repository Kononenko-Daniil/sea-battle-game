//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit4.h"
#include "Unit3.h"

#include <System.JSON.hpp>
#include "Types.h"
#include "ServiceWorker.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sgcBase_Classes"
#pragma link "sgcSocket_Classes"
#pragma link "sgcTCP_Classes"
#pragma link "sgcWebSocket"
#pragma link "sgcWebSocket_Classes"
#pragma link "sgcWebSocket_Classes_Indy"
#pragma link "sgcWebSocket_Client"
#pragma resource "*.dfm"

using namespace std;

TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
    connectionStatus = DISCONNECTED;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
	sgcWebSocketClient1->Connect();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender)
{
	sgcWebSocketClient1->Disconnect();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::sgcWebSocketClient1Connect(TsgcWSConnection *Connection)
{
	connectionStatus = CONNECTED;

	worker.ChangeConnectionStatusUI(connectionStatus, *Label2);
	worker.ChangeConnectionStatusUI(connectionStatus, *Form3->Label4);

	LabeledEdit1->Enabled=true;
	LabeledEdit2->Enabled=true;
	LabeledEdit3->Enabled=true;
	LabeledEdit4->Enabled=true;
    LabeledEdit5->Enabled=true;
	Button3->Enabled=true;

	sgcWebSocketClient1->WriteData("Connected successfully!");
}
//---------------------------------------------------------------------------

void __fastcall TForm6::sgcWebSocketClient1Disconnect(TsgcWSConnection *Connection,
          int Code)
{
	connectionStatus = DISCONNECTED;

	worker.ChangeConnectionStatusUI(connectionStatus, *Label2);
	worker.ChangeConnectionStatusUI(connectionStatus, *Form3->Label4);

	LabeledEdit1->Enabled=false;
	LabeledEdit2->Enabled=false;
	LabeledEdit3->Enabled=false;
	LabeledEdit4->Enabled=false;
	LabeledEdit5->Enabled=false;
	Button3->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button4Click(TObject *Sender)
{
	if(LabeledEdit1->Text != "" && LabeledEdit5->Text != "") {
		TJSONObject *checkCodesRequest = new TJSONObject();

		checkCodesRequest->AddPair("method", CHECK_GUEST_CODE);
		checkCodesRequest->AddPair("room_id", LabeledEdit1->Text);
		checkCodesRequest->AddPair("player_code", LabeledEdit5->Text);

		String request = checkCodesRequest->ToString();

		sgcWebSocketClient1->WriteData(request);

		checkCodesRequest->Free();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button3Click(TObject *Sender)
{
	TJSONObject *generateRoomRequest = new TJSONObject();

	generateRoomRequest->AddPair("method", GENERATE_ROOM);

	String request = generateRoomRequest->ToString();

	sgcWebSocketClient1->WriteData(request);

	generateRoomRequest->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::sgcWebSocketClient1Message(TsgcWSConnection *Connection,
													const UnicodeString Text)
{
    TJSONObject *response = (TJSONObject*) TJSONObject::ParseJSONValue(Text, 0);
	if(response != NULL) {
        requests method = static_cast<requests>(
			StrToInt(response->GetValue("method")->Value())
		);

		switch(method) {
			case CHECK_GUEST_CODE: {
				bool codeStatus = StrToBool(response->GetValue("code_status")->Value());
				bool isMyMove = StrToBool(response->GetValue("my_move")->Value());
				bool isRoomFull = StrToBool(response->GetValue("room_is_full")->Value());

				if(codeStatus) {
					Form3->envProps.roomId = StrToInt(Form6->LabeledEdit1->Text);
					Form3->envProps.playerCode = StrToInt(Form6->LabeledEdit5->Text);
					Form3->envProps.isMyMove = isMyMove;
					Form3->envProps.isRoomFull = isRoomFull;

					Label6->Caption="SUCCESS";
					Label6->Font->Color=clGreen;

					Form3->UpdateRoomInfo();
				} else {
					Label6->Caption="ERROR";
					Label6->Font->Color=clRed;
                }

				break;
			}
			case GENERATE_ROOM: {
				int roomId = StrToInt(response->GetValue("roomId")->Value());
				int firstCode = StrToInt(response->GetValue("firstCode")->Value());
				int secondCode = StrToInt(response->GetValue("secondCode")->Value());

				LabeledEdit2->Text = IntToStr(roomId);
				LabeledEdit3->Text = IntToStr(firstCode);
				LabeledEdit4->Text = IntToStr(secondCode);

                break;
			}
			case NOTIFY_ROOM_CHANGED_FULLNESS: {
				bool isRoomFull = StrToBool(response->GetValue("room_is_full")->Value());
				Form3->envProps.isRoomFull = isRoomFull;

                Form3->UpdateRoomInfo();

                break;
            }
        }

	}
}
//---------------------------------------------------------------------------

