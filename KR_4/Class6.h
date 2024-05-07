#pragma once

#include "Base.h"


class Class6 : public Base
{

public:

	Class6( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

};
