#include "Class3.h"


Class3::Class3( Base* pParentObject, string objectName ) : Base( pParentObject, objectName )
{
	this->ClassNumber = 3;
}

void Class3::Signal( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 3)";
}

void Class3::Handler( string message )
{
	cout << endl << "Signal to " << this->GetPath() << " Text: " << message;
}
