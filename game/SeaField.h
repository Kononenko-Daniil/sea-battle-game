//---------------------------------------------------------------------------

#ifndef SeaFieldH
#define SeaFieldH

#include "Types.h"
#include "Constants.h"

#include <Vcl.Grids.hpp>
#include <vcl.h>
#include <vector>
#include <iostream>

using namespace std;

class SeaField {
	private:
		Constants constants;
        vector<int> ships = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};

	public:
		vector<vector<int>> field { 10, vector<int>(10) };

		bool PlaceShip(int, int, int, int);
		bool CheckShipKilled(pair<int, int>&);
        bool CheckLose();


		int DeleteShip(int, int);
		int KillShip(pair<int, int>&);

		void ClearAll();
		void ClearUnuseful();
		void ApplyFieldToGrid(TDrawGrid&, int, int, TRect&, bool);
		void AutoGenerateField();
        void ApplyUsedCells(SeaField&);

		pair<moveResults, int> ChangeCellByHit(pair<int, int>&);

		friend istream& operator >>(istream&, SeaField&);
		friend ostream& operator <<(ostream&, SeaField&);
};
//---------------------------------------------------------------------------
#endif
