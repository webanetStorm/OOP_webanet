#include "Output.h"


Output::Output( Base* pParent, string name ) : Base( pParent, name )
{
}

void Output::Handler( string command )
{
	if ( command != "Ready to work" )
		cout << endl;

	cout << command;
}
