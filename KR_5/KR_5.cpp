#include <iostream>
using namespace std;

#include "App.h"

int main()
{
	App app( nullptr );
	app.build_tree();
	return app.exec_app();
}
