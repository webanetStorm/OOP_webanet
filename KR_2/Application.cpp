#include "Application.h"
#include <iostream>


Application::Application( Base* pParentObject ) : Base( pParentObject ) {}

void Application::BuildTreeObjects()
{
    Base *pParentObject = this, *pChildObject = nullptr;
    string parentName, childName;
    int classNumber, stateNumber;


    cin >> parentName;
    this->SetObjectName( parentName );

    while ( cin >> parentName >> childName >> classNumber )
    {
        if ( parentName == "endtree" )
            break;

        pParentObject = this->FindOnTree( parentName );

        switch ( classNumber )
        {
            case 2:
                new Class2( pParentObject, childName );
                break;
            case 3:
                new Class3( pParentObject, childName );
                break;
            case 4:
                new Class4( pParentObject, childName );
                break;
            case 5:
                new Class5( pParentObject, childName );
                break;
            case 6:
                new Class6( pParentObject, childName );
                break;
        }
    }

    while ( cin >> parentName >> stateNumber )
    {
        pParentObject = this->FindOnTree( parentName );

        if ( pParentObject )
            pParentObject->SetReadiness( stateNumber );
    }
}

int Application::ExecApp()
{
    cout << this->GetObjectName();

    cout << "\nObject tree";
    this->DisplayHierarchy();

    cout << "\nThe tree of objects and their readiness";
    this->DisplayHierarchyWithReadiness();


    return 0;
}
