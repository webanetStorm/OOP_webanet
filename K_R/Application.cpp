#include "Application.h"
#include <iostream>


Application::Application( Base* pParentObject ) : Base( pParentObject ) {}

void Application::BuildTreeObjects()
{
    string line;
    cin >> line;

    this->SetObjectName( line );


    while ( true )
    {

        cin >> line;
        if ( line.empty() )
            break;

        size_t spaceIndex = line.find( ' ' );
        if ( spaceIndex == string::npos ) 
            continue;

        string parentName = line.substr( 0, spaceIndex ), childName = line.substr( spaceIndex + 1 );
        if ( parentName == childName ) 
            break;


        Base* parentObject = nullptr;

        if ( this->GetObjectName() == parentName )
        {
            parentObject = this;
        }
        else
        {
            for ( Base* obj : this->_childObjects )
            {
                if ( obj->GetObjectName() == parentName )
                {
                    parentObject = obj;
                    break;
                }
            }
        }

        if ( parentObject )
            new Base( parentObject, childName );

    }
}

int Application::ExecApp()
{
    this->DisplayHierarchy();

    return 0;
}
