#pragma once


#include <string>
#include "Class3.h"

using namespace std;


class Class4 : private Class3
{

private:

	string _name;

	int _num;


public:

	Class4( string, int );

	void Print();

};
