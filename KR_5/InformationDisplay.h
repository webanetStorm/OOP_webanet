#pragma once

#include "Base.h"


class InformationDisplay : public Base
{

public:

	InformationDisplay( Base* pParent, string name );

	virtual void HandlerF( string message );

};
