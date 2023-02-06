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
    NOTIFY_ROOM_CHANGED_FULLNESS
};

struct EnvironmentProperties {
	int roomId;
	int playerCode;
	bool isMyMove;
    bool isRoomFull;
};
//---------------------------------------------------------------------------
#endif
