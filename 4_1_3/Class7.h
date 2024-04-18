#pragma once

#include "Class4.h"
#include "Class5.h"


class Class7 : public Class4, public Class5
{

private:

	string _name;


public:

	Class7( string );

	string GetName();

};
