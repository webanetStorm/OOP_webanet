#include "Base.h"


Base::Base( Base* pParent, string name ) : _pParent( pParent ), _name( name )
{
	if ( this->_pParent )
		this->_pParent->_children.push_back( this );
}

Base::~Base()
{
	for ( auto pChild : this->_children )
		delete pChild;

	this->GetRoot()->DeleteLinks( this );
}

bool Base::SetName( string name )
{
	if ( this->_pParent )
		for ( auto pChild : this->_pParent->_children )
			if ( pChild->GetName() == name )
				return false;

	this->_name = name;

	return true;
}

string Base::GetName()
{
	return this->_name;
}

string Base::GetPath()
{
	return this->_pParent ? this->_pParent->_pParent ? this->_pParent->GetPath() + "/" + this->_name : this->_pParent->GetPath() + this->_name : "/";
}

Base* Base::GetRoot()
{
	if ( _pParent )
		_pParent->GetRoot();

	return this;
}

Base* Base::GetParent()
{
	return this->_pParent;
}

Base* Base::GetChildByName( string name )
{
	for ( auto pChild : this->_children )
		if ( pChild->GetName() == name )
			return pChild;

	return nullptr;
}

Base* Base::FindOnBranch( string name )
{
	queue<Base*> queue;
	Base* pFound = nullptr;

	queue.push( this );


	while ( !queue.empty() )
	{
		if ( queue.front()->GetName() == name )
		{
			if ( pFound == nullptr )
				pFound = queue.front();
			else
				return nullptr;
		}

		for ( auto pChild : queue.front()->_children )
			queue.push( pChild );

		queue.pop();
	}


	return pFound;
}

Base* Base::FindOnTree( string name )
{
	Base* pCurrent = this;

	while ( pCurrent->_pParent )
		pCurrent = pCurrent->_pParent;

	return pCurrent->FindOnBranch( name );
}

Base* Base::FindObjectByPath( string path )
{
	Base *pCurrent = this, *pRoot = this->GetRoot();


	if ( path == "/" )
		return pRoot;

	if ( path == "." )
		return this;

	if ( path.substr( 0, 2 ) == "//" )
		return this->FindOnTree( path.substr( 2 ) );

	if ( path.substr( 0, 1 ) == "." )
		return this->FindOnBranch( path.substr( 1 ) );


	if ( path[0] == '/' )
	{
		pCurrent = pRoot;
		path = path.substr( 1 );
	}


	size_t pos = 0;

	while ( ( pos = path.find( '/' ) ) != string::npos )
	{
		pCurrent = pCurrent->GetChildByName( path.substr( 0, pos ) );

		if ( !pCurrent )
			return nullptr;

		path.erase( 0, pos + 1 );
	}


	return pCurrent->GetChildByName( path );
}

bool Base::SetNewParent( Base* pNewParent )
{
	if ( pNewParent && pNewParent != this && !pNewParent->FindOnBranch( this->_name ) && this->_pParent )
	{
		Base* pCurrent = pNewParent;

		while ( pCurrent )
		{
			pCurrent = pCurrent->_pParent;

			if ( pCurrent == this )
				return false;
		}


		this->_pParent->_children.erase( find( this->_pParent->_children.begin(), this->_pParent->_children.end(), this ) );
		pNewParent->_children.push_back( this );
		this->_pParent = pNewParent;

		return true;
	}

	return false;
}

void Base::DeleteChildByName( string name )
{
	Base* pChild = this->GetChildByName( name );

	if ( pChild )
	{
		this->_children.erase( find( this->_children.begin(), this->_children.end(), pChild ) );

		delete pChild;
	}
}

void Base::Display( int level )
{
	cout << endl << string( level * 4, ' ' ) << this->_name;

	for ( auto pChild : this->_children )
		pChild->Display( level + 1 );
}

void Base::DisplayWithReadiness( int level )
{
	cout << endl << string( level * 4, ' ' ) << this->_name << ( this->_readiness == 0 ? " is not ready" : " is ready" );

	for ( auto pChild : this->_children )
		pChild->DisplayWithReadiness( level + 1 );
}

void Base::SetReadiness( int state )
{
	if ( state != 0 )
	{
		Base* current = this->_pParent;

		while ( current != nullptr && current->_readiness != 0 )
			current = current->_pParent;

		if ( current == nullptr )
			this->_readiness = state;
	}
	else
	{
		this->_readiness = state;

		for ( auto pChild : this->_children )
			pChild->SetReadiness( state );
	}
}

int Base::GetReadiness()
{
	return this->_readiness;
}

void Base::SetConnection( TYPE_SIGNAL pSignal, Base* pTarget, TYPE_HANDLER pHandler )
{
	for ( auto elem : _connections )
		if ( elem->Signal == pSignal && elem->Target == pTarget && elem->Handler == pHandler )
			return;

	this->_connections.push_back( new Connection { pSignal, pHandler, pTarget } );
}

void Base::DeleteConnection( TYPE_SIGNAL pSignal, Base* pTarget, TYPE_HANDLER pHandler )
{
	for ( auto it = this->_connections.begin(); it != this->_connections.end(); it++ )
	{
		if ( ( *it )->Signal == pSignal && ( *it )->Target == pTarget && ( *it )->Handler == pHandler )
		{
			this->_connections.erase( it );
			break;
		}
	}
}

void Base::EmitSignal( TYPE_SIGNAL Signal, Base* object, string& command )
{
	if ( !GetReadiness() )
		return;

	TYPE_HANDLER Handler;
	Base* Target;

	( this->*Signal ) ( command );

	for ( auto connection : _connections )
	{

		if ( connection->Signal == Signal && connection->Target->GetReadiness() )
		{

			if ( connection->Target->GetName() == object->GetName() )
			{
				Handler = connection->Handler;
				Target = connection->Target;

				( Target->*Handler ) ( command );

				break;
			}
		}
	}
}

void Base::DeleteLinks( Base* pTarget )
{
	for ( auto it = this->_connections.begin(); it != this->_connections.end(); it++ )
	{
		if ( ( *it )->Target == pTarget )
		{
			delete ( *it );
			this->_connections.erase( it );
			it--;
		}
	}

	for ( auto pChild : this->_children )
		pChild->DeleteLinks( pTarget );
}

void Base::Signal( string& command )
{
}

void Base::Handler( string command )
{
}

vector<string> Base::Explode( string text )
{
	vector<string> words;
	istringstream ist( text );

	for ( string word; ist >> word;)
		words.push_back( word );

	return words;
}
