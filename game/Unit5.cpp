//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	Form3->computerEnemy.myField.ApplyFieldToGrid(*DrawGrid1,
													ARow,
													ACol,
													Rect,
													CheckBox1->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::DrawGrid2DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	Form3->computerEnemy.playerField.ApplyFieldToGrid(*DrawGrid2,
													ARow,
													ACol,
													Rect,
													CheckBox1->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::CheckBox1Click(TObject *Sender)
{
	DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------

