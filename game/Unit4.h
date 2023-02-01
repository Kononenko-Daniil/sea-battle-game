//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TDataModule4 : public TDataModule
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule4 *DataModule4;
//---------------------------------------------------------------------------
#endif
