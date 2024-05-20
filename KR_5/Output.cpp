#include "Output.h"
#include <iostream>

Output::Output( Base* parent, string name ) : Base( parent, name )
{
}

void Output::handler_f( string command )
{
	if ( command != "Ready to work" )
		std::cout << std::endl;
	std::cout << command;
}
