#include "Class4.h"


Class4::Class4( Base* pParentObject, string objectName ) : Base( pParentObject, objectName )
{
	this->ClassNumber = 4;
}

void Class4::Signal( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 4)";
}

void Class4::Handler( string message )
{
	cout << endl << "Signal to " << this->GetPath() << " Text: " << message;
}
