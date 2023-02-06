#ifndef DbContextServiceH
#define DbContextServiceH

#include "Types.h"

#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>


class DbContextService {
	public:
		gameRoom MapGameRoom(TFields&);
};

#endif
