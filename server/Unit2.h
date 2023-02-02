//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "sgcBase_Classes.hpp"
#include "sgcSocket_Classes.hpp"
#include "sgcTCP_Classes.hpp"
#include "sgcWebSocket.hpp"
#include "sgcWebSocket_Classes.hpp"
#include "sgcWebSocket_Server.hpp"
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TDataModule2 : public TDataModule
{
__published:	// IDE-managed Components
	TsgcWebSocketServer *sgcWebSocketServer1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule2 *DataModule2;
//---------------------------------------------------------------------------
#endif
