#include <iostream>
#include "Base.h"


Base::Base( Base* pParentObject, string objectName )
{
	this->_pParentObject = pParentObject;
	this->_objectName = objectName;

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

Base* Base::Find( string name )
{
	if ( this->_objectName == name ) 
		return this;

	for ( auto pChild : this->_childObjects )
		if ( Base* found = pChild->Find( name ) )
			return found;

	return nullptr;
}

Base* Base::FindOnTree( string name )
{
	Base* current = this;

	while ( current->_pParentObject != nullptr )
		current = current->_pParentObject;

	return current->Find( name );
}

Base* Base::FindOnBranch( string name )
{
	if ( this->CountOnBranch( name ) != 1 )
		return nullptr;

	return Find( name );
}

int Base::CountOnBranch( string name )
{
	int result = 0;

	if ( this->_objectName == name )
		result++;

	for ( auto pChild : this->_childObjects )
		result += pChild->CountOnBranch( name );

	return result;
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
	this->_readiness = state;
}