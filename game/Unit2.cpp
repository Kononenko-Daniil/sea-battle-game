//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit4.h"

#include "SeaField.h"
#include "ServiceWorker.h"
#include "Constants.h"

#include <fstream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;

TForm2 *Form2;

SeaField field;
ServiceWorker worker;
Constants constants;

int shipSize = 4;


__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {

}

void __fastcall TForm2::ChooseShipSize(int size) {
    shipSize = size;

	switch (size) {
		case 1: {
			RadioButton4 -> Checked = true;
			RadioButton3 -> Checked = false;
			RadioButton2 -> Checked = false;
			RadioButton1 -> Checked = false;
			break;
		}
		case 2: {
			RadioButton4 -> Checked = false;
			RadioButton3 -> Checked = true;
			RadioButton2 -> Checked = false;
			RadioButton1 -> Checked = false;
			break;
		}
		case 3: {
			RadioButton4 -> Checked = false;
			RadioButton3 -> Checked = false;
			RadioButton2 -> Checked = true;
			RadioButton1 -> Checked = false;
			break;
		}
		case 4: {
			RadioButton4 -> Checked = false;
			RadioButton3 -> Checked = false;
			RadioButton2 -> Checked = false;
			RadioButton1 -> Checked = true;
			break;
		}
	}
}


void __fastcall TForm2::RadioButton1Click(TObject *Sender) {
    ChooseShipSize(4);
}


void __fastcall TForm2::RadioButton2Click(TObject *Sender) {
	ChooseShipSize(3);
}


void __fastcall TForm2::RadioButton3Click(TObject *Sender) {
	ChooseShipSize(2);
}


void __fastcall TForm2::RadioButton4Click(TObject *Sender) {
    ChooseShipSize(1);
}


void __fastcall TForm2::ChangeShipCount(int sSize,
										bool increase) {
	TLabeledEdit& labeledEdit = GetLabeledEditByShipSize(sSize);

	int curCount = StrToInt(labeledEdit.Text);
	increase ? curCount++ : curCount--;
	labeledEdit.Text = IntToStr(curCount);
}


bool __fastcall TForm2::CheckHasShip(int sSize) {
	TLabeledEdit& labeledEdit = GetLabeledEditByShipSize(sSize);

	int curCount = StrToInt(labeledEdit.Text);

	return curCount > 0 ? true : false;
}


TLabeledEdit& TForm2::GetLabeledEditByShipSize(int sSize) {
	switch(sSize) {
		case 1: {
			return *LabeledEdit4;
		}
		case 2: {
			return *LabeledEdit3;
		}
		case 3: {
			return *LabeledEdit2;
		}
		case 4: {
			return *LabeledEdit1;
		}
	}
}


void __fastcall TForm2::DrawGrid1SelectCell(TObject *Sender,
											int ACol,
											int ARow,
											bool &CanSelect) {
	if(RadioGroup2->ItemIndex == 0) {
		int direction = RadioGroup1->ItemIndex;

		if (CheckHasShip(shipSize)){
			bool isShipPlaced = field.PlaceShip(shipSize, direction, ACol, ARow);

			if (isShipPlaced){
				ChangeShipCount(shipSize, false);
			}
		}


	} else {
		int deletedShipSize = field.DeleteShip(ACol, ARow);

		if (deletedShipSize) {
			ChangeShipCount(deletedShipSize, true);
		}

    }

    DrawGrid1->Refresh();
}


void __fastcall TForm2::ClearField() {
	field.ClearAll();

	LabeledEdit1->Text="1";
	LabeledEdit2->Text="2";
	LabeledEdit3->Text="3";
	LabeledEdit4->Text="4";

	DrawGrid1->Refresh();
}


void __fastcall TForm2::CheckBox1Click(TObject *Sender) {
    DrawGrid1->Refresh();
}


void __fastcall TForm2::N2Click(TObject *Sender) {
	if (LabeledEdit1->Text=="0" && LabeledEdit2->Text=="0"
		&& LabeledEdit3->Text=="0" && LabeledEdit4->Text=="0") {
		if (DataModule4->SaveDialog1->Execute()) {
			ofstream fout(DataModule4->SaveDialog1->FileName.c_str());

			fout << field;
			DrawGrid1->Refresh();
		}
	} else {
		ShowMessage(constants.SAVING_FIELD_ERROR_MESSAGE);
	}
}


void __fastcall TForm2::N3Click(TObject *Sender) {
	if(DataModule4->OpenDialog1 -> Execute()) {
		LabeledEdit1->Text="0";
		LabeledEdit2->Text="0";
		LabeledEdit3->Text="0";
		LabeledEdit4->Text="0";

		ifstream fin (DataModule4->OpenDialog1->FileName.c_str());

		fin >> field;
        DrawGrid1->Refresh();
    }

}


void __fastcall TForm2::DrawGrid1DrawCell(TObject *Sender,
											int ACol,
											int ARow,
											TRect &Rect,
											TGridDrawState State) {
	field.ApplyFieldToGrid(*DrawGrid1,
							ARow,
							ACol,
							Rect,
							CheckBox1->Checked);
}


void __fastcall TForm2::Button1Click(TObject *Sender) {
    ClearField();
}

void __fastcall TForm2::Button2Click(TObject *Sender)
{
    LabeledEdit1->Text="0";
	LabeledEdit2->Text="0";
	LabeledEdit3->Text="0";
	LabeledEdit4->Text="0";

	field.AutoGenerateField();

    DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------

