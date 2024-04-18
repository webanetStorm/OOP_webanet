#pragma once

#include "Class1.h"


class Class2 : public Class1
{

private:

	string _name;


public:

	Class2( string );

	string GetName();

};
