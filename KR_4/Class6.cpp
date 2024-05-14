#include "Class6.h"


Class6::Class6( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 6;
}

void Class6::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 6)";
}

void Class6::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}
