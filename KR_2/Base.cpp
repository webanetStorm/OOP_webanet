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

	while ( pCurrent->_pParentObject != nullptr )
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
		Base* pCurrent = queue.front();
		queue.pop();

		if ( pCurrent->GetObjectName() == name )
		{
			if ( pFound == nullptr )
				pFound = pCurrent;
			else
				return nullptr;
		}

		for ( Base* pChild : pCurrent->_childObjects )
			queue.push( pChild );
	}


	return pFound;
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
