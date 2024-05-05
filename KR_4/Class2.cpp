#include "Class2.h"


Class2::Class2( Base* pParentObject, string objectName ) : Base( pParentObject, objectName ) {};

void Class2::Signal( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 2)";
}

void Class2::Handler( string message )
{
	cout << endl << "Signal to " << this->GetPath() << " Text: " << message;
}
