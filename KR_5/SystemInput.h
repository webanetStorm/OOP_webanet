#pragma once

#include "Base.h"


class SystemInput : public Base
{

public:

	SystemInput( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

	void ProcessCommands();

};
