#include "SystemInput.h"
#include <sstream>


SystemInput::SystemInput( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 1;
}

void SystemInput::HandlerF( string message )
{
	string text;

	getline( cin, text );

	this->EmitSignal( SIGNAL_D( Base::SignalF ), this->GetParent(), text );
}
