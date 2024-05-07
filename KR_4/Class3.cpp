#include "Class3.h"


Class3::Class3( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 3;
}

void Class3::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 3)";
}

void Class3::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}