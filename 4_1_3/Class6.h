#pragma once

#include "Class2.h"
#include "Class3.h"


class Class6 : public Class2, public Class3
{

private:

	string _name;


public:

	Class6( string );

	string GetName();

};
