#include "Class1.h"


Class1::Class1( Base* pParentObject, string objectName ) : Base( pParentObject, objectName )
{
};

void Class1::Signal( string& message )
{
	cout << endl << "Signal from " << this->GetPath();
	message += " (class: 1)";
}

void Class1::Handler( string message )
{
	cout << endl << "Signal to " << this->GetPath() << " Text: " << message;
}
