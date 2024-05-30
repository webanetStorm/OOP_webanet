#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DBG_NEW new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW

#include "System.h"


int main()
{
	System system( nullptr );

	system.BuildTreeObjects();

	system.ExecApp();
	_CrtDumpMemoryLeaks();
	return 0;
}
