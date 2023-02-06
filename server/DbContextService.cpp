//---------------------------------------------------------------------------

#pragma hdrstop

#include "DbContextService.h"

gameRoom DbContextService::MapGameRoom(TFields& fields) {
	gameRoom room = {
		fields.FieldByName("RoomId")->AsInteger,
		fields.FieldByName("InviteCodeFirst")->AsInteger,
		fields.FieldByName("InviteCodeSecond")->AsInteger,
		fields.FieldByName("Move")->AsInteger,
		fields.FieldByName("CodeIsUsedFirst")->AsBoolean,
		fields.FieldByName("CodeIsUsedSecond")->AsBoolean,
		fields.FieldByName("GuidFirst")->Value,
		fields.FieldByName("GuidSecond")->Value
	};

    return room;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
