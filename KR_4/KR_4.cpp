#include "Application.h"

int main()
{
	Application app( nullptr );

	app.BuildTreeObjects();

	return app.ExecApp();
}