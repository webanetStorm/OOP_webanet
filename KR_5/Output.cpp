#include "Output.h"
#include <iostream>


Output::Output( Base* pParent, string name ) : Base( pParent, name )
{
}

void Output::handler_f( string message )
{
	if ( message != "Ready to work" )
		cout << endl;

	cout << message;
}
