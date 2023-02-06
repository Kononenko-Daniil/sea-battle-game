//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataModule3 *DataModule3;
//---------------------------------------------------------------------------
__fastcall TDataModule3::TDataModule3(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataModule3::IdHTTPServer1CommandGet(TIdContext *AContext, TIdHTTPRequestInfo *ARequestInfo,
          TIdHTTPResponseInfo *AResponseInfo)
{
	if(ARequestInfo->Document=="/") {
        AResponseInfo->ContentText="Hello";
    }

}
//---------------------------------------------------------------------------
