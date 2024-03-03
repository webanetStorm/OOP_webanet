#pragma once

#include <vector>
#include <string>

using namespace std;


class Base
{

private:

    string _objectName;

    Base* _pParentObject;

    vector<Base*> _childObjects;


public:

    Base( Base* pParentObject, string objectName = "Base_Object" );

    ~Base();

    bool SetObjectName( string name );

    string GetObjectName();

    Base* GetParentObject();

    Base* GetChildByName( string name );

    void DisplayHierarchy();

};
