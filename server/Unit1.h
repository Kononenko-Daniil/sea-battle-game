#ifndef Unit1H
#define Unit1H

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include "sgcBase_Classes.hpp"
#include "sgcSocket_Classes.hpp"
#include "sgcTCP_Classes.hpp"
#include "sgcWebSocket.hpp"
#include "sgcWebSocket_Classes.hpp"
#include "sgcWebSocket_Server.hpp"
#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomHTTPServer.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdHTTPServer.hpp>

#include "DbContextService.h"


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TsgcWebSocketServer *sgcWebSocketServer1;
	TDBGrid *DBGrid1;
	TDBNavigator *DBNavigator1;
	void __fastcall Memo1Change(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall sgcWebSocketServer1Message(TsgcWSConnection *Connection, const UnicodeString Text);
	void __fastcall sgcWebSocketServer1Disconnect(TsgcWSConnection *Connection, int Code);
	void __fastcall sgcWebSocketServer1Connect(TsgcWSConnection *Connection);




private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	void __fastcall Log(String);
	void __fastcall NotifyRoomChangedFullness(String, roomFullness);
	void __fastcall DisconnectPlayerFromRoom(String);

	guestCodeCheckInfo __fastcall CheckGuestCode(int, int, String);
	gameRoomInfo __fastcall GenerateRoom();
	String __fastcall GetTargetPlayerGuid(String);

    DbContextService dbContext;
};

extern PACKAGE TForm1 *Form1;

#endif
