#include "Application.h"
#include <iostream>


Application::Application( Base* pParentObject ) : Base( pParentObject ) {}

void Application::BuildTreeObjects()
{
    Base *pParentObject = this, *pChildObject = nullptr;
    string parentName, childName;
    int classNumber;


    cin >> parentName;
    this->SetObjectName( parentName );

    while ( cin >> parentName >> childName >> classNumber )
    {
        if ( parentName == "endtree" )
            break;

        if ( pChildObject != nullptr && parentName == pChildObject->GetObjectName() )
            pParentObject = pChildObject;

        if ( pParentObject->GetChildByName( childName ) == nullptr && parentName == pParentObject->GetObjectName() )
            pChildObject = new Base( pParentObject, childName );
    }
}

int Application::ExecApp()
{
    cout << this->GetObjectName();

    this->DisplayHierarchy();

    return 0;
}
