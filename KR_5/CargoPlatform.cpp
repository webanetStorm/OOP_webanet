#include "CargoPlatform.h"


CargoPlatform::CargoPlatform( Base* pParent, string name ) : Base( pParent, name )
{
	this->ClassNumber = 3;
}

void CargoPlatform::SignalF( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 3)";
}

void CargoPlatform::HandlerF( string message )
{
	cout << endl << "Signal to " << GetPath() << " Text:  " << message;
}
