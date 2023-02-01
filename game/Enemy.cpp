//---------------------------------------------------------------------------

#pragma hdrstop

#include "Types.h"
#include "Enemy.h"

using namespace std;

Enemy::Enemy () {
	myField.AutoGenerateField();
}


pair<moveResults, int> Enemy::PlayerMoveAction(pair<int, int>& cellCoords) {
	pair<moveResults, int> playerMoveResult = myField.ChangeCellByHit(cellCoords);

	return playerMoveResult;
}


pair<int, int>& Enemy::MoveAction() {
	srand(time(NULL));

	int x, y;
	do {
		x = rand()%10;
		y = rand()%10;
	} while(playerField.field[x][y] != 0);

	pair<int, int> coords = make_pair(x, y);

	return coords;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
