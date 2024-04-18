#include "Class5.h"


Class5::Class5( string name ) : _name( name + "_5" ), Class1( name + "_5" )
{
}

string Class5::GetName()
{
	return _name;
}
