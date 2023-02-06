#ifndef Unit2H
#define Unit2H

#include <System.Classes.hpp>
#include <Vcl.Dialogs.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomHTTPServer.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdHTTPServer.hpp>


class TDataModule2 : public TDataModule
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TADOTable *ADOTable1;
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;

private:	// User declarations
public:		// User declarations
	__fastcall TDataModule2(TComponent* Owner);
};

extern PACKAGE TDataModule2 *DataModule2;

#endif
