#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Base
{

private:

	int _readiness;

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

	Base* FindOnTree( string name );

	Base* FindOnBranch( string name );

	Base* FindObjectByPath( string path );

	bool SetNewParent( Base* pNewParent );

	void DeleteChildByName( string name );

	void DisplayHierarchy( int level = 0 );

	void DisplayHierarchyWithReadiness( int level = 0 );

	void SetReadiness( int state );

};
