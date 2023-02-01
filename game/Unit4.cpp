//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
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
