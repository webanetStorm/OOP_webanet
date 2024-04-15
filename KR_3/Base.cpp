#include <iostream>
#include <queue>
#include "Base.h"


Base::Base( Base* pParentObject, string objectName ) : _pParentObject( pParentObject ), _objectName( objectName ), _readiness( 0 )
{
	if ( pParentObject )
		pParentObject->_childObjects.push_back( this );
}

Base::~Base()
{
	for ( auto pChild : this->_childObjects )
		delete pChild;
}

bool Base::SetObjectName( string name )
{
	if ( this->_pParentObject )
		for ( auto pChild : this->_pParentObject->_childObjects )
			if ( pChild->GetObjectName() == name )
				return false;

	this->_objectName = name;

	return true;
}

string Base::GetObjectName()
{
	return this->_objectName;
}

Base* Base::GetParentObject()
{
	return this->_pParentObject;
}

Base* Base::GetChildByName( string name )
{
	for ( auto pChild : this->_childObjects )
		if ( pChild->GetObjectName() == name )
			return pChild;

	return nullptr;
}

Base* Base::FindOnTree( string name )
{
	Base* pCurrent = this;

	while ( pCurrent->_pParentObject )
		pCurrent = pCurrent->_pParentObject;

	return pCurrent->FindOnBranch( name );
}

Base* Base::FindOnBranch( string name )
{
	queue<Base*> queue;
	Base* pFound = nullptr;

	queue.push( this );


	while ( !queue.empty() )
	{
		if ( queue.front()->GetObjectName() == name )
		{
			if ( pFound == nullptr )
				pFound = queue.front();
			else
				return nullptr;
		}

		for ( auto pChild : queue.front()->_childObjects )
			queue.push( pChild );

		queue.pop();
	}


	return pFound;
}

Base* Base::FindRoot()
{
	Base* pRoot = this;

	while ( pRoot->_pParentObject )
		pRoot = pRoot->_pParentObject;

	return pRoot;
}

Base* Base::FindObjectByPath( string path )
{
	Base* pCurrent = this;


	if ( path == "/" )
		return this->FindRoot();

	if ( path == "." )
		return this;

	if ( path.substr( 0, 2 ) == "//" )
		return this->FindOnTree( path.substr( 2 ) );

	if ( path.substr( 0, 1 ) == "." )
		return this->FindOnBranch( path.substr( 1 ) );


	if ( path[0] == '/' )
	{
		pCurrent = this->FindRoot();
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

bool Base::SetNewParent( Base* pNewParent, string path )
{
	if ( !pNewParent )
	{ // ���������, ���������� �� newParent
		cout << path << "     Head object is not found" << endl;

		return false;
	}

	if ( !this->_pParentObject || this == pNewParent )
	{ // ���������, �� �������� �� this �������� �������� ��� newParent ������� ��������
		cout << path << "     Redefining the head object failed" << endl;

		return false;
	}

	Base* pCurrent = pNewParent;
	while ( pCurrent )
	{ // ���������, �� ����������� �� newParent � ��������� this
		if ( pCurrent == this )
		{
			cout << path << "     Redefining the head object failed" << endl;

			return false;
		}

		pCurrent = pCurrent->_pParentObject;
	}

	for ( auto pChild : pNewParent->_childObjects )
	{ // ���������, ��� �� � newParent ������������ � ����� �� ������
		if ( pChild->GetObjectName() == this->_objectName )
		{
			cout << path << "     Dubbing the names of subordinate objects" << endl;

			return false;
		}
	}



	if ( this->_pParentObject )
	{ // ��������� ��������������� ��������� �������
		for ( size_t i = 0; i < this->_pParentObject->_childObjects.size(); i++ )
		{
			if ( this->_pParentObject->_childObjects[i] == this )
			{
				this->_pParentObject->_childObjects.erase( this->_pParentObject->_childObjects.begin() + i );
				break;
			}
		}
	}

	pNewParent->_childObjects.push_back( this );
	this->_pParentObject = pNewParent;


	cout << "New head object: " << pNewParent->GetObjectName() << endl;

	return true;
}

void Base::DeleteChildByName( string name )
{
	for ( auto it = this->_childObjects.begin(); it != this->_childObjects.end(); it++ )
	{
		if ( ( *it )->GetObjectName() == name )
		{
			delete *it;

			this->_childObjects.erase( it );

			return;
		}
	}
}

void Base::DisplayHierarchy( int level )
{
	cout << endl << string( level * 4, ' ' ) << this->_objectName;

	for ( auto pChild : this->_childObjects )
		pChild->DisplayHierarchy( level + 1 );
}

void Base::DisplayHierarchyWithReadiness( int level )
{
	cout << endl << string( level * 4, ' ' ) << this->_objectName << ( this->_readiness == 0 ? " is not ready" : " is ready" );

	for ( auto pChild : this->_childObjects )
		pChild->DisplayHierarchyWithReadiness( level + 1 );
}

void Base::SetReadiness( int state )
{
	if ( state != 0 )
	{
		Base* pCurrent = this->_pParentObject;

		while ( pCurrent != nullptr && pCurrent->_readiness != 0 )
			pCurrent = pCurrent->_pParentObject;

		if ( pCurrent == nullptr )
			this->_readiness = state;
	}
	else
	{
		this->_readiness = state;

		for ( auto pChild : this->_childObjects )
			pChild->SetReadiness( state );
	}
}
