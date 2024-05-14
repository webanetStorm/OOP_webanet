#pragma once

#include "Base.h"


class InformationDisplay : public Base
{

public:

	InformationDisplay( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

	void DisplayMessage( string message );

};
