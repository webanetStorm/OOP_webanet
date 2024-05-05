#include "Class6.h"


Class6::Class6( Base* pParentObject, string objectName ) : Base( pParentObject, objectName ) {};

void Class6::Signal( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 6)";
}

void Class6::Handler( string message )
{
	cout << endl << "Signal to " << this->GetPath() << " Text: " << message;
}

