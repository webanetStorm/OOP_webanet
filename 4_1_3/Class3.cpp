#include "Class3.h"


Class3::Class3( string name ) : _name( name + "_3" ), Class1( name + "_3" )
{
}

string Class3::GetName()
{
	return _name;
}
