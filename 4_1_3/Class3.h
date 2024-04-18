#pragma once

#include "Class1.h"


class Class3 : public Class1
{

private:

	string _name;


public:

	Class3( string );

	string GetName();

};
