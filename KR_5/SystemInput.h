#pragma once

#include "Base.h"


class SystemInput : public Base
{

public:

	SystemInput( Base* pParent, string name );

	virtual void HandlerF( string message );

};
