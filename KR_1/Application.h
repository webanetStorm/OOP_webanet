#pragma once

#include "Base.h"
#include "Class1.h"


class Application : public Base
{

public:

	Application( Base* pHeadObject );

	void BuildTreeObjects();

	int ExecApp();

};
