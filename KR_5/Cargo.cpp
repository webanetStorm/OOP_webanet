#include "Cargo.h"
#include "CargoPlatform.h"


Cargo::Cargo( Base* pParent, double length, double width, double height, string name ) : CargoPlatform( pParent, name ), _length( length ), _width( width ), _height( height )
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
	cout << endl << "Signal to " << this->GetPath() << " Text:  " << message;
}
