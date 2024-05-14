#include "Class4.h"


Class4::Class4( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 4;
}

void Class4::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 4)";
}

void Class4::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}
