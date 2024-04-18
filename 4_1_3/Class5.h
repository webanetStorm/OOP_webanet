#pragma once

#include "Class1.h"


class Class5 : public virtual Class1
{

private:

	string _name;


public:

	Class5( string );

	string GetName();

};
