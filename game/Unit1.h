//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TDrawGrid *DrawGrid1;
	TDrawGrid *DrawGrid2;
	TMainMenu *MainMenu1;
	TMenuItem *Game1;
	TMenuItem *Game2;
	TMenuItem *N1;
	TMenuItem *N2;
	TMemo *Memo1;
	TLabel *Label1;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TOpenDialog *OpenDialog1;
	void __fastcall N1Click(TObject *Sender);
	void __fastcall Game2Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
