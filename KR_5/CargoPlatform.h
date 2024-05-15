#pragma once

#include "Base.h"


class CargoPlatform : public Base
{

public:

	CargoPlatform( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

};
