#include "SystemInput.h"


SystemInput::SystemInput( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 1;
}

void SystemInput::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 1)";
}

void SystemInput::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}
