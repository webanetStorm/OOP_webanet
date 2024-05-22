#include "Output.h"


Output::Output( Base* parent, string name ) : Base( parent, name )
{
}

void Output::Handler( string command )
{
	if ( command != "Ready to work" )
		cout << endl;

	cout << command;
}
