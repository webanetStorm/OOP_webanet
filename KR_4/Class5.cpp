#include "Class5.h"


Class5::Class5( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 5;
}

void Class5::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 5)";
}

void Class5::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}