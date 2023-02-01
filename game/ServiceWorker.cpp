//---------------------------------------------------------------------------

#pragma hdrstop

#include "ServiceWorker.h"
#include "Constants.h"
#include "Types.h"

#include "SeaField.h"
#include <vcl.h>

char ServiceWorker::GetLetterByNumber(int num) {
	char letter = num + 65;

    return letter;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
