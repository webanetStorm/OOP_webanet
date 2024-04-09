#pragma once


#include <string>
#include "Class2.h"

using namespace std;


class Class3 : private Class2
{

private:

	string _name;

	int _num;


public:

	Class3( string, int );

	void Print();

};
