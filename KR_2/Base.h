#pragma once

#include <vector>
#include <string>

using namespace std;


class Base
{

private:

    int _readiness = 0;

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

    Base* FindOnBranch( string name );

    void DisplayHierarchy();

    void TreeTraversal( int level = 0 );

};
