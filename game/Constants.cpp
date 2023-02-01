//---------------------------------------------------------------------------

#pragma hdrstop

#include "Constants.h"
#include <vcl.h>

using namespace std;

Constants::Constants() {
	sea_cell -> LoadFromFile("img/sea.bmp");
	sea_hit_cell -> LoadFromFile("img/sea_hit.bmp");

	near_cell -> LoadFromFile("img/near.bmp");
	near_hit_cell -> LoadFromFile("img/near_hit.bmp");

	ship_cell -> LoadFromFile("img/ship.bmp");
	ship_hit_cell -> LoadFromFile("img/ship_hit.bmp");
    ship_kill_cell -> LoadFromFile("img/ship_kill.bmp");
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
