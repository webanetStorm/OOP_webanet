#pragma once

#include "Base.h"


class Class3 : public Base
{

public:

	Class3( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

};
