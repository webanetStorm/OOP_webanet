#include "Application.h"
#include <iostream>


int main()
{
    Application app( nullptr );

    app.BuildTreeObjects();

    return app.ExecApp();
}
