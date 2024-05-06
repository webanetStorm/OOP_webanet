#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Base;


#define SIGNAL_D( signal_f ) ( TYPE_SIGNAL ) ( &signal_f )
#define HANDLER_D( hendler_f ) ( TYPE_HANDLER ) ( &hendler_f )

typedef void ( Base::*TYPE_SIGNAL ) ( string& message );
typedef void ( Base::*TYPE_HANDLER ) ( string message );


struct Connection
{

	TYPE_SIGNAL Signal;

	Base* TargetObject;

	TYPE_HANDLER Handler;

};


class Base
{

private:

	int _readiness;

	string _objectName;

	Base* _pParentObject;

	vector<Base*> _childObjects;

	vector<Connection*> _connections;


public:

	int ClassNumber;


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

	void SetConnection( TYPE_SIGNAL pSignal, Base* pTarget, TYPE_HANDLER pHandler );

	void DeleteConnection( TYPE_SIGNAL pSignal, Base* pTarget, TYPE_HANDLER pHandler );

	void EmitSignal( TYPE_SIGNAL pSignal, string message );

	string GetPath();

};

