#pragma once

#include  "Base.h"


class Class5 : public Base
{

public:

	Class5( Base* pParentObject, string objectName );

	void Signal( string& message );

	void Handler( string message );

};
