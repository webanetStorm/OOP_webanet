#include "System.h"


int main()
{
	System system( nullptr );

	system.BuildTreeObjects();

	return system.ExecApp();
}
