//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "SeaField.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

using namespace std;
SeaField myField;
SeaField enemyField;

Graphics::TBitmap *_sea = new Graphics::TBitmap();
Graphics::TBitmap *_sea_hit = new Graphics::TBitmap();
Graphics::TBitmap *_near_ = new Graphics::TBitmap();
Graphics::TBitmap *_near_hit = new Graphics::TBitmap();
Graphics::TBitmap *_ship = new Graphics::TBitmap();
Graphics::TBitmap *_ship_hit = new Graphics::TBitmap();
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm3::DrawField(
					SeaField& field,
					TDrawGrid& grid,
					int row,
					int col,
					TRect &Rect) {
	switch(field.getField()[row][col]) {
		case 0: {
			grid.Canvas -> StretchDraw(Rect, _sea);
			break;
		}
		case 1: {
			grid.Canvas -> StretchDraw(Rect, _sea_hit);
			break;
		}
		case 2: {
			if (CheckBox1->Checked) {
				grid.Canvas -> StretchDraw(Rect, _near_);
			} else {
				grid.Canvas -> StretchDraw(Rect, _sea);
			}

			break;
		}
		case 3: {
			if (CheckBox1->Checked) {
				grid.Canvas -> StretchDraw(Rect, _near_hit);
			} else {
				grid.Canvas -> StretchDraw(Rect, _sea_hit);
			}

			break;
		}
		case 4: {
			grid.Canvas -> StretchDraw(Rect, _ship);
			break;
		}
		case 5: {
			grid.Canvas -> StretchDraw(Rect, _ship_hit);
			break;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	DrawField(myField, *DrawGrid1, ARow, ACol, Rect);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
	OpenDialog1->InitialDir = ExtractFilePath(ParamStr(0));

	_sea -> LoadFromFile("sea.bmp");
	_sea_hit -> LoadFromFile("sea_hit.bmp");

	_near_ -> LoadFromFile("near.bmp");
	_near_hit -> LoadFromFile("near_hit.bmp");

	_ship -> LoadFromFile("ship.bmp");
	_ship_hit -> LoadFromFile("ship_hit.bmp");
}
//---------------------------------------------------------------------------
