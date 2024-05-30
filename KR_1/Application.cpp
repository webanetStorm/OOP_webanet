#include "Application.h"
#include <iostream>


Application::Application( Base* pParentObject ) : Base( pParentObject ) {}

void Application::BuildTreeObjects()
{
    Base* pParentObject = this, * pChildObject = nullptr;
    string parentName, childName;

    cin >> parentName;
    this->SetObjectName( parentName );

    while ( cin >> parentName >> childName )
    {
        if ( parentName == childName )
            break;

        if ( pChildObject != nullptr && parentName == pChildObject->GetObjectName() )
            pParentObject = pChildObject;

        if ( pParentObject->GetChildByName( childName ) == nullptr && parentName == pParentObject->GetObjectName() )
            pChildObject = new Class1( pParentObject, childName );
    }

    delete pChildObject;
}

int Application::ExecApp()
{
    cout << this->GetObjectName();

    this->DisplayHierarchy();

    return 0;
}
