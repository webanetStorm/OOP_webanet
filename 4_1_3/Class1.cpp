#include "Class1.h"


Class1::Class1( string name ) : _name( name + "_1" )
{
}

string Class1::GetName()
{
	return _name;
}
