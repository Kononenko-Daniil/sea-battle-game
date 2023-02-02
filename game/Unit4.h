//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Dialogs.hpp>
#include "sgcBase_Classes.hpp"
#include "sgcSocket_Classes.hpp"
#include "sgcTCP_Classes.hpp"
#include "sgcWebSocket.hpp"
#include "sgcWebSocket_Classes.hpp"
#include "sgcWebSocket_Classes_Indy.hpp"
#include "sgcWebSocket_Client.hpp"
//---------------------------------------------------------------------------
class TDataModule4 : public TDataModule
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TsgcWebSocketClient *sgcWebSocketClient1;
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule4 *DataModule4;
//---------------------------------------------------------------------------
#endif
