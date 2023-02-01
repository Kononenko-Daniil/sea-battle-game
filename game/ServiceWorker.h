//---------------------------------------------------------------------------

#ifndef ServiceWorkerH
#define ServiceWorkerH

#include "SeaField.h"
#include "Types.h"
#include <Vcl.Grids.hpp>
#include <vcl.h>

class ServiceWorker {
	private:
		Constants constants;
	public:
		char GetLetterByNumber(int);
};
//---------------------------------------------------------------------------
#endif
