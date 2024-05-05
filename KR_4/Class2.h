#pragma once

#include "Base.h"


class Class2 : public Base
{

public:

	Class2( Base* pParentObject, string objectName );

	void Signal( string& message );

	void Handler( string message );

};
