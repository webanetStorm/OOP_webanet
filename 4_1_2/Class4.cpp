#include <iostream>
#include "Class4.h"


Class4::Class4( string name, int num ) : Class3( name, num ), _name( name + "_4" ), _num( num * num * num * num )
{
}

void Class4::Print()
{
	cout << _name << ' ' << _num << endl;
}
