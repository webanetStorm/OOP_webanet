#include "CraneController.h"


CraneController::CraneController( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 2;
}

void CraneController::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 2)";
}

void CraneController::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}
