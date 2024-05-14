#include "ConstructionFloor.h"


ConstructionFloor::ConstructionFloor( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 4;
}

void ConstructionFloor::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 4)";
}

void ConstructionFloor::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}
