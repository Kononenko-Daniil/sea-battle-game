#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"

#include "Types.h"

#include <fstream>

#pragma package(smart_init)
#pragma resource "*.dfm"


using namespace std;
TForm3 *Form3;


__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner){
	envProps = {
		-1, -1,
		false, false
    };
}


void __fastcall TForm3::DrawGrid1DrawCell(TObject *Sender,
											int ACol,
											int ARow,
											TRect &Rect,
											TGridDrawState State) {
	myField.ApplyFieldToGrid(*DrawGrid1,
							ARow,
							ACol,
							Rect,
							CheckBox1->Checked);
}


void __fastcall TForm3::DrawGrid2DrawCell(TObject *Sender,
											int ACol,
											int ARow,
											TRect &Rect,
											TGridDrawState State) {
	enemyField.ApplyFieldToGrid(*DrawGrid2,
								ARow,
								ACol,
								Rect,
								CheckBox1->Checked);
}


void __fastcall TForm3::DrawGrid2SelectCell(TObject *Sender,
											int ACol,
											int ARow,
											bool &CanSelect) {
	if (statusBar.moveStatus == MINE && statusBar.gameStatus == RUNNING) {
		if(statusBar.gameType == COMPUTER) {
			if(enemyField.field[ARow][ACol] == 0){
				pair<int, int> cellCoords = make_pair(ARow, ACol);
				pair<moveResults, int> moveResult = computerEnemy.PlayerMoveAction(cellCoords);

				CreateMoveLogInfo(MINE,
									moveResult,
									ARow,
									ACol);

				enemyField.ApplyUsedCells(computerEnemy.myField);

				bool isEnemyLosed = computerEnemy.myField.CheckLose();

				if(isEnemyLosed) {
					EndGame("Player");
				} else {
                    pair<int, int> enemyMoveCoords = computerEnemy.MoveAction();
					pair<moveResults, int> enemyMoveResult =
						myField.ChangeCellByHit(enemyMoveCoords);
					CreateMoveLogInfo(ENEMY,
										enemyMoveResult,
										enemyMoveCoords.first,
										enemyMoveCoords.second);
					computerEnemy.playerField.ApplyUsedCells(myField);

					bool isMeLosed = myField.CheckLose();

					if(isMeLosed) {
                        EndGame("Enemy");
					}
				}

				DrawGrid1->Refresh();
				DrawGrid2->Refresh();

				Form5->DrawGrid1->Refresh();
				Form5->DrawGrid2->Refresh();
            }
		} else if (statusBar.gameType == ONLINE) {

        }
    }
}


void __fastcall TForm3::Button1Click(TObject *Sender)
{
	if(statusBar.fieldFileIsUploaded) {
		statusBar.gameStatus = RUNNING;
        statusBar.moveStatus = MINE;

		Log("System: Game - start; Your turn;");

		Button1->Enabled=false;
		Button4->Enabled=false;
		N1->Enabled=true;
		N2->Enabled=false;
		N7->Enabled=true;
		N8->Enabled=true;
		N3->Enabled=false;
		N6->Enabled=false;
	} else {
		statusBar.gameStatus = STOPPED;
		statusBar.moveStatus = ENEMY;

		ShowMessage(constants.EMPTY_FIELD_ERROR_MESSAGE);

		Button1->Enabled=false;
	}
}


void __fastcall TForm3::Button3Click(TObject *Sender)
{
    Form5->Show();
}


void __fastcall TForm3::Button4Click(TObject *Sender)
{
	myField.AutoGenerateField();
	DrawGrid1->Refresh();

	statusBar.fieldFileIsUploaded = true;
	Button1->Enabled = true;
}


void __fastcall TForm3::N2Click(TObject *Sender)
{
	if(DataModule4 -> OpenDialog1 -> Execute()) {
		ifstream fin (DataModule4 -> OpenDialog1->FileName.c_str());

		fin >> myField;
		DrawGrid1->Refresh();
		statusBar.fieldFileIsUploaded = true;

		if(statusBar.gameType == COMPUTER){
			Button1->Enabled = true;
		} else {
			Button2->Enabled=true;
		}

	}
}


void __fastcall TForm3::N4Click(TObject *Sender)
{
	statusBar.gameType = COMPUTER;

	NewGame();
}


void __fastcall TForm3::N5Click(TObject *Sender)
{
	statusBar.gameType = ONLINE;

	NewGame();

	Label4->Visible=true;
	Button2->Visible=true;

    Form6->Show();
}


void __fastcall TForm3::N6Click(TObject *Sender)
{
	Form2->Show();
}


void __fastcall TForm3::N7Click(TObject *Sender)
{
    NewGame();
}


void __fastcall TForm3::N8Click(TObject *Sender)
{
	if(DataModule4->OpenDialog1->Execute()) {
		Memo1->Lines->SaveToFile(DataModule4->OpenDialog1->FileName.c_str());
    }
}


void __fastcall TForm3::CheckBox1Click(TObject *Sender)
{
    DrawGrid1->Refresh();
}


void __fastcall TForm3::Memo1Change(TObject *Sender)
{
	if(Memo1->Lines->Count > 4) {
		Memo1->ScrollBars = ssVertical;
	}
}


void __fastcall TForm3::EndGame(String winnerName) {
	statusBar.gameStatus = STOPPED;
	Log("System: " + winnerName + " winned! Game - stop.");
	ShowMessage(winnerName + " winned!!!");

	N1->Enabled=true;
    N2->Enabled=false;
	N3->Enabled=true;
	N6->Enabled=true;
}


void __fastcall TForm3::NewGame() {
    // Default statuses
	statusBar = GameStatusBar();

	// Clear history
	for(int i = Memo1->Lines->Count; i >= 0; i--) {
		Memo1->Lines->Delete(i);
	}

	// Clear seafields
	myField.ClearAll();
	enemyField.ClearAll();
	computerEnemy.myField.ClearAll();
	computerEnemy.myField.AutoGenerateField();
    computerEnemy.playerField.ClearAll();


	// Clear ui
	CheckBox1->Checked=false;
	Button1->Enabled=false;
	Button4->Enabled=true;
	N1->Enabled=true;
    N2->Enabled=true;
	N3->Enabled=true;
	N6->Enabled=true;
	Label4->Visible=false;
	Button2->Visible=false;
    Button2->Enabled=false;

    // Refresh Grids
	DrawGrid1->Refresh();
	DrawGrid2->Refresh();
	Form5->DrawGrid1->Refresh();
	Form5->DrawGrid2->Refresh();
}


void __fastcall TForm3::Log(String message) {
	Memo1->Lines->Add(message);
}


void __fastcall TForm3::CreateMoveLogInfo(moveStatuses sender,
											pair<moveResults, int>& moveResult,
											int row,
											int col) {
	String logMessage = (sender == MINE ? "Me: " : "Enemy: ") + String(worker.GetLetterByNumber(col)) +
		IntToStr(row) + " - ";
	switch(moveResult.first) {
		case HIT: {
			logMessage += "HIT.";
			break;
		}
		case MISS: {
			logMessage += "MISS.";
			break;
		}
		case KILL: {
			logMessage += "KILL. " + IntToStr(moveResult.second+1) + "-cell ship.";
			break;
		}
		case ERR: {
			logMessage = "";
			break;
		}
	}

	if(logMessage != "") {
		Log(logMessage);
	}
}


void TForm3::UpdateRoomInfo() {
	Panel2->Caption = IntToStr(envProps.roomId) + "-" +
						IntToStr(envProps.playerCode) + "-" +
						(envProps.isMyMove ? "my move" : "enemy`s move") + "-" +
						(envProps.isRoomFull? "room is full" : "wait players");
}

