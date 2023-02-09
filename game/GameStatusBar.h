//---------------------------------------------------------------------------

#ifndef GameStatusBarH
#define GameStatusBarH

#include "Types.h"
#include <vcl.h>

class GameStatusBar {
	public:
		bool fieldFileIsUploaded;
		gameTypes gameType;
		gameStatuses gameStatus;
		moveStatuses moveStatus;

		roomStatuses roomStatus;
		int roomId;
		int playerCode;

        std::pair<int, int> myLastMoveCoords;

		String GetRoomStatusStr();

		GameStatusBar();
};
//---------------------------------------------------------------------------
#endif
