//---------------------------------------------------------------------------

#ifndef GameStatusBarH
#define GameStatusBarH

#include "Types.h"

class GameStatusBar {
	public:
		bool fieldFileIsUploaded;
		gameTypes gameType;
		gameStatuses gameStatus;
		moveStatuses moveStatus;

		GameStatusBar();
};
//---------------------------------------------------------------------------
#endif
