#pragma once

#include "Base.h"


class ConstructionFloor : public Base
{

public:

	ConstructionFloor( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

};
