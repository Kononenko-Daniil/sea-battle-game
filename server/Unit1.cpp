//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

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

void __fastcall TForm1::Log(String sender, String logMessage) {
    Memo1->Lines->Add(sender + ": " + logMessage);
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
	Log("SYSTEM", "Server successfully started. Start logging.");
}
//---------------------------------------------------------------------------
