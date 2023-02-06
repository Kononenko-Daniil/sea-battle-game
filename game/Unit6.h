#ifndef Unit6H
#define Unit6H

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "sgcBase_Classes.hpp"
#include "sgcSocket_Classes.hpp"
#include "sgcTCP_Classes.hpp"
#include "sgcWebSocket.hpp"
#include "sgcWebSocket_Classes.hpp"
#include "sgcWebSocket_Classes_Indy.hpp"
#include "sgcWebSocket_Client.hpp"

#include "Types.h"
#include "ServiceWorker.h"

using namespace std;


class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TPanel *Panel1;
	TButton *Button1;
	TButton *Button2;
	TLabeledEdit *LabeledEdit1;
	TsgcWebSocketClient *sgcWebSocketClient1;
	TPanel *Panel2;
	TLabel *Label3;
	TPanel *Panel3;
	TLabel *Label4;
	TLabeledEdit *LabeledEdit2;
	TLabel *Label5;
	TButton *Button3;
	TLabeledEdit *LabeledEdit3;
	TLabeledEdit *LabeledEdit4;
	TButton *Button4;
	TLabeledEdit *LabeledEdit5;
	TLabel *Label6;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall sgcWebSocketClient1Connect(TsgcWSConnection *Connection);
	void __fastcall sgcWebSocketClient1Disconnect(TsgcWSConnection *Connection, int Code);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall sgcWebSocketClient1Message(TsgcWSConnection *Connection, const UnicodeString Text);
	void __fastcall Button3Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);

    connectionStatuses connectionStatus;
	ServiceWorker worker;
};

extern PACKAGE TForm6 *Form6;

#endif
