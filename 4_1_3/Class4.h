#pragma once

#include "Class1.h"


class Class4 : public virtual Class1
{

private:

	string _name;


public:

	Class4( string );

	string GetName();

};
