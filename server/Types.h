//---------------------------------------------------------------------------

#ifndef TypesH
#define TypesH

#include <vcl.h>

enum requests : int {
	CHECK_GUEST_CODE,
	GENERATE_ROOM,
	NOTIFY_ROOM_CHANGED_FULLNESS
};

struct gameRoom {
	int roomId, firstCode, secondCode, move;
	bool codeIsUsedFirst, codeIsUsedSecond;
	String firstPlayerGuid, secondPlayerGuid;
};

struct gameRoomInfo {
	int roomId, firstCode, secondCode, move;
};

enum roomFullness {
	FULL,
    PARTIAL
};

struct guestCodeCheckInfo {
	bool codeIsValid, moveIsMyne, roomIsFull;
};
//---------------------------------------------------------------------------
#endif
