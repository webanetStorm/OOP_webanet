#pragma once

#include "Base.h"


class Class2 : public Base
{

public:

	Class2( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

};
