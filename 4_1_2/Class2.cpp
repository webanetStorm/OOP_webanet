#include <iostream>
#include "Class2.h"


Class2::Class2( string name, int num ) : Class1( name, num ), _name( name + "_2" ), _num( num * num )
{
}

void Class2::Print()
{
	cout << _name << ' ' << _num << endl;
}
