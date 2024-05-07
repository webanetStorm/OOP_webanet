#pragma once

#include "Base.h"


class Class1 : public Base
{

public:

	Class1( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

};
