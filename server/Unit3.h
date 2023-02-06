//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomHTTPServer.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdHTTPServer.hpp>
#include <IdContext.hpp>
//---------------------------------------------------------------------------
class TDataModule3 : public TDataModule
{
__published:	// IDE-managed Components
	TIdHTTPServer *IdHTTPServer1;
	void __fastcall IdHTTPServer1CommandGet(TIdContext *AContext, TIdHTTPRequestInfo *ARequestInfo,
          TIdHTTPResponseInfo *AResponseInfo);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule3 *DataModule3;
//---------------------------------------------------------------------------
#endif
