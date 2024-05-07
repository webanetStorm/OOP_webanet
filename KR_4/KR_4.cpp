#include "Application.h"

int main()
{
	Application ob_cl_application( nullptr );
	ob_cl_application.BuildTreeObjects();
	return ob_cl_application.ExecApp();
}