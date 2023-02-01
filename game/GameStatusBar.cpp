//---------------------------------------------------------------------------

#pragma hdrstop

#include "GameStatusBar.h"
#include "Types.h"

GameStatusBar::GameStatusBar() {
	fieldFileIsUploaded = false;
	gameType = COMPUTER;
	gameStatus = STOPPED;
	moveStatus = MINE;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
