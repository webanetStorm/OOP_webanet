#pragma once

#include  "Base.h"


class Class4 : public Base
{

public:

	Class4( Base* pParentObject, string objectName );

	void Signal( string& message );

	void Handler( string message );

};
