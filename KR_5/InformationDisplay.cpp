#include "InformationDisplay.h"


InformationDisplay::InformationDisplay( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 6;
}

void InformationDisplay::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 6)";
}

void InformationDisplay::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}
