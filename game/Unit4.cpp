//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma link "sgcBase_Classes"
#pragma link "sgcSocket_Classes"
#pragma link "sgcTCP_Classes"
#pragma link "sgcWebSocket"
#pragma link "sgcWebSocket_Classes"
#pragma link "sgcWebSocket_Classes_Indy"
#pragma link "sgcWebSocket_Client"
#pragma resource "*.dfm"
TDataModule4 *DataModule4;
//---------------------------------------------------------------------------
__fastcall TDataModule4::TDataModule4(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataModule4::DataModuleCreate(TObject *Sender)
{
    OpenDialog1->InitialDir = ExtractFilePath(ParamStr(0));
	SaveDialog1->InitialDir = ExtractFilePath(ParamStr(0));
}
//---------------------------------------------------------------------------
