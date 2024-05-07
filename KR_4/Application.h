#pragma once

#include "Base.h"
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"
#include "Class6.h"


class Application : public Base
{

public:

	Application( Base* pParent );

	void BuildTreeObjects();

	int ExecApp();

};
