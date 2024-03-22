#include <iostream>
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
	if ( this->_objectName == name )
		return this;

	for ( auto pChild : this->_childObjects )
		if ( Base* pFound = pChild->FindOnBranch( name ) )
			return pFound;

	return nullptr;
}

Base* Base::FindRoot()
{
	Base* pRoot = this;

	while ( pRoot->_pParentObject != nullptr )
		pRoot = pRoot->_pParentObject;

	return pRoot;
}

Base* Base::FindObjectByPath( string path )
{
	Base* pCurrent = this;
	string name;
	size_t pos = 0;


	if ( path == "/" )
		return this->FindRoot();

	if ( path == "." )
		return this;

	if ( ( name = path.substr( 2 ) ) == "//" )
		return this->FindOnTree( name );

	if ( ( name = path.substr( 1 ) ) == "." )
		return this->FindOnBranch( name );


	if ( path[0] == '/' )
	{
		pCurrent = this->FindRoot();
		path = path.substr( 1 );
	}

	while ( ( pos = path.find( '/' ) ) != string::npos )
	{
		name = path.substr( 0, pos );
		pCurrent = pCurrent->GetChildByName( name );

		if ( !pCurrent ) 
			return nullptr;

		path.erase( 0, pos + 1 );
	}


	return pCurrent->GetChildByName( path );
}

bool Base::SetNewParent( Base* newParent )
{
	if ( !newParent || this == newParent || this->_pParentObject == nullptr || newParent->FindOnBranch( this->_objectName ) )
		return false;


	auto siblings = this->_pParentObject->_childObjects;
	siblings.erase( remove( siblings.begin(), siblings.end(), this ), siblings.end() );

	newParent->_childObjects.push_back( this );
	this->_pParentObject = newParent;


	return true;
}

void Base::DeleteChildByName( string name )
{
	auto it = find_if( _childObjects.begin(), _childObjects.end(), [&]( Base* child )
	{
		return child->GetObjectName() == name;
	} );

	if ( it != _childObjects.end() )
	{
		delete *it;
		_childObjects.erase( it );
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
