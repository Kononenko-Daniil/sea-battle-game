//---------------------------------------------------------------------------

#ifndef SeaFieldH
#define SeaFieldH

#include <vector>
#include <iostream>

using namespace std;

class SeaField {
	private:
		vector<vector<int>> field { 10, vector<int>(10) };
	public:
        vector<vector<int>>& getField();
		bool PlaceShip(int, int, int, int);
		int DeleteShip(int, int);
		void ClearAll();
		void ClearUnuseful();
		friend istream& operator >>(istream&, SeaField&);
		friend ostream& operator <<(ostream&, SeaField&);
};
//---------------------------------------------------------------------------
#endif
