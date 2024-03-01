#pragma once

#include <vector>
#include <string>

using namespace std;


class Base
{

private:

    string _objectName = "Base_Object";
    
    Base* _pParentObject = nullptr;


protected:

    vector<Base*> _childObjects;


public:

    Base( Base* pParentObject = nullptr, string objectName = "Base_Object" );

    bool SetObjectName( string name );

    string GetObjectName();

    Base* GetParentObject();

    void DisplayHierarchy( int level = 0 );

    void AddChild( Base* pChild );

};
