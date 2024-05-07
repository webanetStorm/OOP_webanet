#include "Class2.h"


Class2::Class2( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 2;
}

void Class2::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 2)";
}

void Class2::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}