#pragma once

#include "Base.h"
#include "SystemInput.h"
#include "CraneController.h"
#include "CargoPlatform.h"
#include "ConstructionFloor.h"
#include "Cargo.h"
#include "InformationDisplay.h"


class System : public Base
{

public:

	System( Base* pParent );

	void BuildTreeObjects();

	int ExecApp();

};
