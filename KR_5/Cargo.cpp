#include "Cargo.h"


Cargo::Cargo( Base* pParent, double length, double width, double height, string name ) : Base( pParent, name )
{
	this->ClassNumber = 5;
}

void Cargo::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 5)";
}

void Cargo::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}
