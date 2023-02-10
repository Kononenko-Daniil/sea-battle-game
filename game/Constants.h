//---------------------------------------------------------------------------

#ifndef ConstantsH
#define ConstantsH

#include <vcl.h>
#include <string>

using namespace std;
class Constants {
	public:
		Graphics::TBitmap *sea_cell = new Graphics::TBitmap();
		Graphics::TBitmap *sea_hit_cell = new Graphics::TBitmap();
		Graphics::TBitmap *near_cell = new Graphics::TBitmap();
		Graphics::TBitmap *near_hit_cell = new Graphics::TBitmap();
		Graphics::TBitmap *ship_cell = new Graphics::TBitmap();
		Graphics::TBitmap *ship_hit_cell = new Graphics::TBitmap();
		Graphics::TBitmap *ship_kill_cell = new Graphics::TBitmap();

		Constants();

		const String SAVING_FIELD_ERROR_MESSAGE =
			"You can`t save sea field, until you have any ship!";
		const String EMPTY_FIELD_ERROR_MESSAGE =
			"You can`t start the game, until your field is empty!";
		const String ROOM_ID_EDIT_FIELD_EMPTY_MESSAGE =
			"You need to input room ID and player code!";
		const String ROOM_CONNECT_FIELD_EMPTY_MESSAGE =
			"You need fill your seafield to connect to room!";
		const String ROOM_PARAMETRS_INCORRECT_MESSAGE =
			"Something is incorrect! Please check entered data.";
};
//---------------------------------------------------------------------------
#endif
