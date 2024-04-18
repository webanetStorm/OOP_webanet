#pragma once

#include "Class6.h"
#include "Class7.h"


class Class8 : public Class6, public Class7
{

private:

	string _name;


public:

	Class8( string );

	string GetName();

};
