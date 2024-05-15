#include "InformationDisplay.h"


InformationDisplay::InformationDisplay( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 6;
}

void InformationDisplay::HandlerF( string message )
{
	if ( message != "Ready to work" )
		cout << endl;

	cout << message;
}
