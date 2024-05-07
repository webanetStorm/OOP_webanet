#include "Class1.h"


Class1::Class1( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 1;
}

void Class1::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 1)";
}

void Class1::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}