#pragma hdrstop

#include "GameStatusBar.h"
#include "Types.h"

GameStatusBar::GameStatusBar() {
	fieldFileIsUploaded = false;
	gameType = COMPUTER;
	gameStatus = STOPPED;
	moveStatus = ENEMY;

	roomStatus = NONE;
	roomId = -1;
	playerCode = -1;

    myLastMoveCoords = std::make_pair(-1, -1);
}


String GameStatusBar::GetRoomStatusStr() {
    String roomStatus_str;

	switch(roomStatus) {
		case FULL: { roomStatus_str="room is full"; break; }
		case PARTIAL: { roomStatus_str="waiting players"; break; }
		case NONE: { roomStatus_str="none"; break; }
	}

    return roomStatus_str;
}

#pragma package(smart_init)
