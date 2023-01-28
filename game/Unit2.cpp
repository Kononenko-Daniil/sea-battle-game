//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "SeaField.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;

TForm2 *Form2;
SeaField pole;
Graphics::TBitmap *sea = new Graphics::TBitmap();
Graphics::TBitmap *sea_hit = new Graphics::TBitmap();
Graphics::TBitmap *near_ = new Graphics::TBitmap();
Graphics::TBitmap *near_hit = new Graphics::TBitmap();
Graphics::TBitmap *ship = new Graphics::TBitmap();
Graphics::TBitmap *ship_hit = new Graphics::TBitmap();
int shipSize = 4;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	OpenDialog1->InitialDir = ExtractFilePath(ParamStr(0));
	SaveDialog1->InitialDir = ExtractFilePath(ParamStr(0));

	sea -> LoadFromFile("sea.bmp");
	sea_hit -> LoadFromFile("sea_hit.bmp");

	near_ -> LoadFromFile("near.bmp");
	near_hit -> LoadFromFile("near_hit.bmp");

	ship -> LoadFromFile("ship.bmp");
	ship_hit -> LoadFromFile("ship_hit.bmp");
}

//---------------------------------------------------------------------------
void __fastcall TForm2::DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
    switch(pole.getField()[ARow][ACol]) {
		case 0: {
			DrawGrid1 -> Canvas -> StretchDraw(Rect, sea);
			break;
		}
		case 1: {
			DrawGrid1 -> Canvas -> StretchDraw(Rect, sea_hit);
			break;
		}
		case 2: {
			if (CheckBox1->Checked) {
				DrawGrid1 -> Canvas -> StretchDraw(Rect, near_);
			} else {
				DrawGrid1 -> Canvas -> StretchDraw(Rect, sea);
			}

			break;
		}
		case 3: {
			if (CheckBox1->Checked) {
				DrawGrid1 -> Canvas -> StretchDraw(Rect, near_hit);
			} else {
				DrawGrid1 -> Canvas -> StretchDraw(Rect, sea_hit);
			}

			break;
		}
		case 4: {
			DrawGrid1 -> Canvas -> StretchDraw(Rect, ship);
			break;
		}
		case 5: {
			DrawGrid1 -> Canvas -> StretchDraw(Rect, ship_hit);
			break;
		}
	}
}
void __fastcall TForm2::ChooseShipSize(int size) {
	switch (size) {
		case 1: {
			RadioButton4 -> Checked = true;
			RadioButton3 -> Checked = false;
			RadioButton2 -> Checked = false;
			RadioButton1 -> Checked = false;
			shipSize = 1;
			break;
		}
		case 2: {
			RadioButton4 -> Checked = false;
			RadioButton3 -> Checked = true;
			RadioButton2 -> Checked = false;
			RadioButton1 -> Checked = false;
			shipSize = 2;
			break;
		}
		case 3: {
			RadioButton4 -> Checked = false;
			RadioButton3 -> Checked = false;
			RadioButton2 -> Checked = true;
			RadioButton1 -> Checked = false;
            shipSize = 3;
			break;
		}
		case 4: {
			RadioButton4 -> Checked = false;
			RadioButton3 -> Checked = false;
			RadioButton2 -> Checked = false;
			RadioButton1 -> Checked = true;
			shipSize = 4;
			break;
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{
    ChooseShipSize(4);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton2Click(TObject *Sender)
{
	ChooseShipSize(3);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton3Click(TObject *Sender)
{
	ChooseShipSize(2);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton4Click(TObject *Sender)
{
    ChooseShipSize(1);
}
void __fastcall TForm2::ChangeShipCount(int sSize, bool increase) {
	switch(sSize) {
		case 1: {
			int curCount = StrToInt(LabeledEdit4->Text);
			increase ? curCount++ : curCount--;
			LabeledEdit4->Text = IntToStr(curCount);
            break;
		}
		case 2: {
			int curCount = StrToInt(LabeledEdit3->Text);
			increase ? curCount++ : curCount--;
			LabeledEdit3->Text = IntToStr(curCount);
			break;
		}
		case 3: {
			int curCount = StrToInt(LabeledEdit2->Text);
			increase ? curCount++ : curCount--;
			LabeledEdit2->Text = IntToStr(curCount);
			break;
		}
		case 4: {
			int curCount = StrToInt(LabeledEdit1->Text);
            increase ? curCount++ : curCount--;
			LabeledEdit1->Text = IntToStr(curCount);
			break;
		}
	}
}
bool __fastcall TForm2::CheckHasShip(int sSize) {
    int curCount = 0;

    switch(sSize) {
		case 1: {
			curCount = StrToInt(LabeledEdit4->Text);
			break;
		}
		case 2: {
			curCount = StrToInt(LabeledEdit3->Text);
			break;
		}
		case 3: {
			curCount = StrToInt(LabeledEdit2->Text);
			break;
		}
		case 4: {
			curCount = StrToInt(LabeledEdit1->Text);
            break;
		}
	}
	return curCount > 0 ? true : false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DrawGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)

{
	if(RadioGroup2->ItemIndex == 0) {
        int direction;
		switch (RadioGroup1->ItemIndex) {
			case 0: {
				direction = 0;
				break;
			}
			case 1: {
				direction = 1;
				break;

			}
		}

		if (CheckHasShip(shipSize)){
			bool placed = pole.PlaceShip(shipSize, direction, ACol, ARow);
			if (placed){
				ChangeShipCount(shipSize, false);
			}
		}


	} else {
		int deleteSize = pole.DeleteShip(ACol, ARow);
		if (deleteSize) {
			ChangeShipCount(deleteSize, true);
        }

    }

    DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	pole.ClearAll();
	LabeledEdit1->Text="1";
	LabeledEdit2->Text="2";
	LabeledEdit3->Text="3";
	LabeledEdit4->Text="4";
    DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::CheckBox1Click(TObject *Sender)
{
    DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N2Click(TObject *Sender)
{
	if (LabeledEdit1->Text=="0" && LabeledEdit2->Text=="0"
		&& LabeledEdit3->Text=="0" && LabeledEdit4->Text=="0") {
		if (SaveDialog1->Execute()) {
			ofstream fout(SaveDialog1->FileName.c_str());
			fout << pole;
			DrawGrid1->Refresh();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N3Click(TObject *Sender)
{
	if(OpenDialog1 -> Execute()) {
        LabeledEdit1->Text="0";
		LabeledEdit2->Text="0";
		LabeledEdit3->Text="0";
		LabeledEdit4->Text="0";

		ifstream fin (OpenDialog1->FileName.c_str());
		fin >> pole;
        DrawGrid1->Refresh();
    }

}
//---------------------------------------------------------------------------

