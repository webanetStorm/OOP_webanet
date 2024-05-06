#pragma once

#include  "Base.h"


class Class6 : public Base
{

public:

	Class6( Base* pParentObject, string objectName );

	void Signal( string& message );

	void Handler( string message );

};
