#ifndef __BASE__H
#define __BASE__H


#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>


#define SIGNAL_D( func )(TYPE_SIGNAL)( &func )
#define HANDLER_D( func )(TYPE_HANDLER)( &func )

using namespace std;
class Base;

typedef void ( Base::*TYPE_SIGNAL ) ( string& message );
typedef void ( Base::*TYPE_HANDLER ) ( string message );


struct Connection
{

	TYPE_SIGNAL Signal;

	TYPE_HANDLER Handler;

	Base* Target;

};


class Base
{

private:

	int _readiness = 1;

	string _name;

	Base* _pParent;

	vector<Base*> _children;

	vector<Connection*> _connections;


public:

	Base( Base* pParent, string name = "Base Object" );

	~Base();

	bool SetName( string name );

	string GetName();

	string GetPath();

	Base* GetRoot();

	Base* GetParent();

	Base* GetChildByName( string name );

	Base* FindOnBranch( string name );

	Base* FindOnTree( string name );

	Base* FindObjectByPath( string path );

	bool SetNewParent( Base* pNewParent );

	void DeleteChildByName( string name );

	void SetReadiness( int state );

	int GetReadiness();

	void Display( int level = 0 );

	void DisplayWithReadiness( int level = 0 );

	void SetConnection( TYPE_SIGNAL pSignal, Base* pTarget, TYPE_HANDLER pHandler );

	void DeleteConnection( TYPE_SIGNAL pSignal, Base* pTarget, TYPE_HANDLER pHandler );

	void EmitSignal( TYPE_SIGNAL Signal, Base* object, string& command );

	void DeleteLinks( Base* pTarget );

	virtual void Signal( string& command );

	virtual void Handler( string command );

	vector<string> Explode( string text );

};


#endif
