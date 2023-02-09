//---------------------------------------------------------------------------

#ifndef TypesH
#define TypesH

enum moveResults {
	HIT,
	KILL,
	MISS,
	ERR
};

enum gameTypes {
	ONLINE,
	COMPUTER
};

enum gameStatuses {
	RUNNING,
    STOPPED
};

enum moveStatuses {
	MINE,
    ENEMY
};

enum connectionStatuses {
	CONNECTED,
    DISCONNECTED
};

enum requests {
	CHECK_GUEST_CODE,
	GENERATE_ROOM,
	NOTIFY_ROOM_CHANGED_FULLNESS,
	MOVE,
    MOVE_ANSWER
};

enum roomStatuses {
	FULL,
	PARTIAL,
    NONE
};

struct moveAnswer {
	int killedShipLen;
	bool isLosed;
	moveResults moveResult;
};
//---------------------------------------------------------------------------
#endif
