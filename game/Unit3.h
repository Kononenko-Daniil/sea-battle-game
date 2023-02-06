//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>

#include "SeaField.h"
#include "Enemy.h"
#include "Constants.h"
#include "ServiceWorker.h"
#include "GameStatusBar.h"
#include "Types.h"

using namespace std;
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TDrawGrid *DrawGrid1;
	TDrawGrid *DrawGrid2;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TLabel *Label1;
	TLabel *Label2;
	TMemo *Memo1;
	TLabel *Label3;
	TCheckBox *CheckBox1;
	TButton *Button1;
	TPanel *Panel1;
	TMenuItem *N6;
	TButton *Button3;
	TMenuItem *N7;
	TMenuItem *N8;
	TButton *Button4;
	TLabel *Label4;
	TButton *Button2;
	TPanel *Panel2;
	void __fastcall DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall DrawGrid2DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall DrawGrid2SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall Memo1Change(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	void __fastcall DrawField(SeaField&, TDrawGrid&, int, int, TRect&);
	void __fastcall Log(String);
	void __fastcall CreateMoveLogInfo(moveStatuses, pair<moveResults, int>&, int, int);
	void __fastcall EndGame(String winnerName);
	void __fastcall NewGame();
    void __fastcall UpdateRoomInfo();

    SeaField myField;
	SeaField enemyField;
	Enemy computerEnemy;
	Constants constants;
	ServiceWorker worker;
	GameStatusBar statusBar;
    EnvironmentProperties envProps;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
