//---------------------------------------------------------------------------

#pragma hdrstop

#include "SeaField.h"
#include <vector>
#include <iostream>
#include <string>

#include <iostream>
#include <vcl.h>

using namespace std;
// Cells
// 0 - sea cell; 1 - sea hit cell;
// 2 - near ship cell; 3 - near ship hit cell;
// 4 - ship cell; 5 - ship hit cell; 6 - ship kill cell;

// Directions
// 0 - vertical; 1 - horizontal;


void SeaField::AutoGenerateField() {
	ClearAll();
	srand(time(NULL));
	int direction, shipSize, x, y;

	for(int i = 0; i < 10; i++) {
		shipSize = ships[i];
		direction = rand()%2;
		x = rand()%10;
		y = rand()%10;

		while(!PlaceShip(shipSize, direction, x, y)) {
			x = rand()%10;
			y = rand()%10;
			direction = rand()%2;
        }
    }
}


void SeaField::ClearUnuseful() {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			int x_left = j == 0 ? 0 : j-1;
			int y_left = i == 0 ? 0 : i-1;

			int x_right = j == 9 ? 9 : j+1;
			int y_right = i == 9 ? 9 : i+1;

			bool hasShip = false;
			for(int x = x_left; x <= x_right; x++) {
				for(int y = y_left; y <= y_right; y++) {
					if(field[y][x] == 4) {
						hasShip = true;
						break;
                    }
				}
				if(hasShip) {
					break;
                }
			}

			if(!hasShip) {
                field[i][j] = 0;
			}
        }
    }
}


void SeaField::ClearAll() {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			field[i][j] = 0;
        }
	}
}


bool SeaField::PlaceShip(int size, int direction, int x, int y) {
	if(field[y][x] == 0){
		if(direction == 0){
			if (y + (size-1) <= 9) {
				int x1, y1, x2, y2;

				x1 = x-1 < 0 ? 0 : x-1;
				x2 = x+1 > 9 ? 9 : x+1;
				y1 = y-1 < 0 ? 0 : y-1;
				y2 = y+size > 9 ? 9 : y+size;

				for(int i = y1; i <= y2; i++) {
					for (int j = x1; j <= x2; j++) {
						if (field[i][j] != 0 && field[i][j] != 2) {
							return false;
						}
					}
				}

				for(int i = y1; i <= y2; i++) {
					for (int j = x1; j <= x2; j++) {
						field[i][j] = 2;
					}
				}

				for (int i = y; i < y+size; i++) {
					field[i][x] = 4;
				}
			}else {
				return false;
			}
		} else if (direction == 1) {
			if (x + (size-1) <= 9) {
				int x1, y1, x2, y2;

				x1 = x-1 < 0 ? 0 : x-1;
				x2 = x+size > 9 ? 9 : x+size;
				y1 = y-1 < 0 ? 0 : y-1;
				y2 = y+1 > 9 ? 9 : y+1;

				for(int i = y1; i <= y2; i++) {
					for (int j = x1; j <= x2; j++) {
						if (field[i][j] != 0 && field[i][j] != 2) {
							return false;
						}
					}
				}

				for(int i = y1; i <= y2; i++) {
					for (int j = x1; j <= x2; j++) {
						field[i][j] = 2;
					}
				}

				for (int i = x; i < x+size; i++) {
					field[y][i] = 4;
				}
			} else {
				return false;
			}
		}

		return true;
	}

    return false;
}


int SeaField::DeleteShip(int x, int y) {
	if(field[y][x] == 4) {
		int size = 1;
		//Delete horizontally
		if (x != 0) {
			int i = x-1;
			while(i >= 0 && field[y][i] == 4) {
				field[y][i] = 0;
				i--;
				size++;
			}
		}
		if (x != 9) {
			int i = x+1;
			while(i <= 9 && field[y][i] == 4) {
				field[y][i] = 0;
				i++;
				size++;
			}
		}

		//Delete vertically
		if (y != 0) {
			int i = y-1;
			while(i >= 0 && field[i][x] == 4) {
				field[i][x] = 0;
				i--;
				size++;
			}
		}
		if (y != 9) {
			int i = y+1;
			while(i <= 9 && field[i][x] == 4) {
				field[i][x] = 0;
				i++;
				size++;
			}
		}

		//Delete cell
		field[y][x] = 0;

		ClearUnuseful();
		return size;
	}

	return 0;
}


bool SeaField::CheckShipKilled(pair<int, int>& cellCoords) {
	int x = cellCoords.second;
	int y = cellCoords.first;

	//Check horizontally
	if (x != 0) {
		int i = x-1;
		while(i >= 0 && (field[y][i] == 5 || field[y][i] == 4)) {
            if(field[y][i] == 4) {
				return false;
			}
            i--;
		}
	}
	if (x != 9) {
		int i = x+1;
		while(i <= 9 && (field[y][i] == 5 || field[y][i] == 4)) {
			if(field[y][i] == 4) {
				return false;
			}
			i++;
		}
	}

	//Check vertically
	if (y != 0) {
		int i = y-1;
		while(i >= 0 && (field[i][x] == 5 || field[i][x] == 4)) {
			if(field[i][x] == 4) {
                return false;
            }
			i--;
		}
	}
	if (y != 9) {
		int i = y+1;
		while(i <= 9 && (field[i][x] == 5 || field[i][x] == 4)) {
			if(field[i][x] == 4) {
                return false;
            }
			i++;
		}
	}

	return true;
}


int SeaField::KillShip(pair<int, int>& cellCoords) {
	int size = 0;
    int x = cellCoords.second;
	int y = cellCoords.first;

	//Delete horizontally
	if (x > 0) {
		int i = x-1;
		while(i >= 0 && field[y][i] == 5) {
			field[y][i] = 6;
			i--;
			size++;
		}
	}
	if (x < 9) {
		int i = x+1;
		while(i <= 9 && field[y][i] == 5) {
			field[y][i] = 6;
			i++;
			size++;
		}
	}

	//Delete vertically
	if (y > 0) {
		int i = y-1;
		while(i >= 0 && field[i][x] == 5) {
			field[i][x] = 6;
			i--;
			size++;
		}
	}
	if (y < 9) {
		int i = y+1;
		while(i <= 9 && field[i][x] == 5) {
			field[i][x] = 6;
			i++;
			size++;
		}
	}

	//Delete cell
	field[y][x] = 6;

	return size;
}


istream& operator >>(istream& in, SeaField& pole) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			in >> pole.field[i][j];
		}
	}

	return in;
}


ostream& operator <<(ostream& out, SeaField& pole) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			out << pole.field[i][j] << " ";
		}
        out << endl;
	}

	return out;
}


void SeaField::ApplyFieldToGrid(TDrawGrid& grid,
									int row,
									int col,
									TRect &Rect,
									bool withOreol) {
	switch(field[row][col]) {
		case 0: {
			grid.Canvas -> StretchDraw(Rect, constants.sea_cell);
			break;
		}
		case 1: {
			grid.Canvas -> StretchDraw(Rect, constants.sea_hit_cell);
			break;
		}
		case 2: {
			if (withOreol) {
				grid.Canvas -> StretchDraw(Rect, constants.near_cell);
			} else {
				grid.Canvas -> StretchDraw(Rect, constants.sea_cell);
			}

			break;
		}
		case 3: {
			if (withOreol) {
				grid.Canvas -> StretchDraw(Rect, constants.near_hit_cell);
			} else {
				grid.Canvas -> StretchDraw(Rect, constants.sea_hit_cell);
			}

			break;
		}
		case 4: {
			grid.Canvas -> StretchDraw(Rect, constants.ship_cell);
			break;
		}
		case 5: {
			grid.Canvas -> StretchDraw(Rect, constants.ship_hit_cell);
			break;
		}
		case 6: {
			grid.Canvas -> StretchDraw(Rect, constants.ship_kill_cell);
			break;
		}
	}
}


pair<moveResults, int> SeaField::ChangeCellByHit(pair<int, int>& cellCoords) {
	int cellType = field[cellCoords.first][cellCoords.second];
	pair<moveResults, int> result;

	switch(cellType) {
		case 0: {
			field[cellCoords.first][cellCoords.second] = 1;
			result = make_pair(MISS, 0);

			break;
		}
		case 2: {
			field[cellCoords.first][cellCoords.second] = 3;
			result = make_pair(MISS, 0);

			break;
		}
		case 4: {
			bool isShipKilled = CheckShipKilled(cellCoords);
			if(isShipKilled) {
				int killedShipSize = KillShip(cellCoords);
				result = make_pair(KILL, killedShipSize);

				break;
			}

            field[cellCoords.first][cellCoords.second] = 5;
			result = make_pair(HIT, 0);

			break;
		}
		default: {
			result = make_pair(ERR, 0);

            break;
		}
	}

    return result;
}

bool SeaField::CheckLose() {
    for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(field[i][j] == 4 || field[i][j] == 5) {
				return false;
            }
		}
	}

    return true;
}

void SeaField::ApplyUsedCells(SeaField& seafield) {
	for(int i = 0; i<10; i++) {
		for(int j = 0; j < 10; j++) {
			if(seafield.field[i][j] != 2 && seafield.field[i][j] != 4) {
				field[i][j] = seafield.field[i][j];
            }
        }
    }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
