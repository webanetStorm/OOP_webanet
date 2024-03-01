#pragma once

#include "Base.h"


class Application : public Base
{

public:

	Application( Base* pHeadObject );

	void BuildTreeObjects();

	int ExecApp();

};
