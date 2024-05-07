#pragma once

#include "Base.h"


class Class5 : public Base
{

public:

	Class5( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

};
