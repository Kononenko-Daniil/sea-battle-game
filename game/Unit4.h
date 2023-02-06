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

#include "Types.h"
#include "ServiceWorker.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>

using namespace std;
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

    ServiceWorker worker;
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule4 *DataModule4;
//---------------------------------------------------------------------------
#endif
