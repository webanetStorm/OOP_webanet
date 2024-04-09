#include <iostream>
#include "Class3.h"


Class3::Class3( string name, int num ) : Class2( name, num ), _name( name + "_3" ), _num( num * num * num )
{
}

void Class3::Print()
{
	cout << _name << ' ' << _num << endl;
}
