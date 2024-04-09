#pragma once


#include <string>
#include "Class1.h"

using namespace std;


class Class2 : private Class1
{

private:

	string _name;

	int _num;


public:

	Class2( string, int );

	void Print();

};
