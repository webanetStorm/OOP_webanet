#pragma once

#include "Base.h"


class Class4 : public Base
{

public:

	Class4( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

};
