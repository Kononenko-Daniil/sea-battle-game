//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma link "sgcBase_Classes"
#pragma link "sgcSocket_Classes"
#pragma link "sgcTCP_Classes"
#pragma link "sgcWebSocket"
#pragma link "sgcWebSocket_Classes"
#pragma link "sgcWebSocket_Server"
#pragma resource "*.dfm"
TDataModule2 *DataModule2;
//---------------------------------------------------------------------------
__fastcall TDataModule2::TDataModule2(TComponent* Owner)
	: TDataModule(Owner)
{
	OpenDialog1->InitialDir = ExtractFilePath(ParamStr(0));
    SaveDialog1->InitialDir = ExtractFilePath(ParamStr(0));
}
//---------------------------------------------------------------------------
