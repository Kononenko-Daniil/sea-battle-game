//---------------------------------------------------------------------------

#pragma hdrstop

#include "SeaField.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
// Cells
// 0 - sea cell; 1 - sea hit cell;
// 2 - near ship cell; 3 - near ship hit cell;
// 4 - ship cell; 5 - ship hit cell;

// Directions
// 0 - vertical; 1 - horizontal;

vector<vector<int>>& SeaField::getField() {
	return field;
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
		}
	}

	return true;
}

int SeaField::DeleteShip(int x, int y) {
	if(field[y][x] == 4) {
		int size = 1;
		//Delete horizontally
		if (x != 0) {
			int i = x-1;
			while(field[y][i] == 4 && i >= 0) {
				field[y][i] = 0;
				i--;
				size++;
			}
		}
		if (x != 9) {
			int i = x+1;
			while(field[y][i] == 4 && i <= 9) {
				field[y][i] = 0;
				i++;
				size++;
			}
		}

		//Delete vertically
		if (y != 0) {
			int i = y-1;
			while(field[i][x] == 4 && i >= 0) {
				field[i][x] = 0;
				i--;
				size++;
			}
		}
		if (y != 9) {
			int i = y+1;
			while(field[i][x] == 4 && i <= 9) {
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
//---------------------------------------------------------------------------
#pragma package(smart_init)
