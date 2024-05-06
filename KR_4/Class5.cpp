#include "Class5.h"


Class5::Class5( Base* pParentObject, string objectName ) : Base( pParentObject, objectName )
{
	this->ClassNumber = 5;
}

void Class5::Signal( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 5)";
}

void Class5::Handler( string message )
{
	cout << endl << "Signal to " << this->GetPath() << " Text: " << message;
}
