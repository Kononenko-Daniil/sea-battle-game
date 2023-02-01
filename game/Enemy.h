//---------------------------------------------------------------------------

#ifndef EnemyH
#define EnemyH

#include "SeaField.h"
#include "Types.h"
#include "ServiceWorker.h"

using namespace std;

class Enemy {
	private:
		ServiceWorker worker;

	public:
		SeaField myField;
		SeaField playerField;

		Enemy();

		pair<int, int>& MoveAction();
		pair<moveResults, int> ChangeCell(pair<int, int>&);
		pair<moveResults, int> PlayerMoveAction(pair<int, int>&);
};
//---------------------------------------------------------------------------
#endif
