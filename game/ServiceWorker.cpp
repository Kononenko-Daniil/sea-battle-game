//---------------------------------------------------------------------------

#pragma hdrstop

#include "ServiceWorker.h"
#include "Constants.h"
#include "Types.h"

#include "SeaField.h"
#include <vcl.h>
#include <chrono>

using namespace std;
char ServiceWorker::GetLetterByNumber(int num) {
	char letter = num + 65;

    return letter;
}

String ServiceWorker::GenerateClientId() {
	srand(time(NULL));
	String clientId = "";

	for(int i = 0; i < 10; i++) {
		int num = rand()%10;
        clientId += IntToStr(num);
	}

    return clientId;
}

void ServiceWorker::ChangeConnectionStatusUI(connectionStatuses status, TLabel& label) {
	switch(status) {
		case CONNECTED: {
			label.Caption = "CONNECTED";
			label.Font->Color = clGreen;

			break;
		}
		case DISCONNECTED: {
			label.Caption = "DISCONNECTED";
			label.Font->Color = clRed;

			break;
        }
    }
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
