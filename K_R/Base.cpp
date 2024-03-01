#include <iostream>
#include "Base.h"


Base::Base( Base* pParentObject, string objectName )
{
	this->_pParentObject = pParentObject;
	this->_objectName = objectName;

	if ( pParentObject )
		pParentObject->_childObjects.push_back( this );
}

bool Base::SetObjectName( string name )
{
	if ( this->_pParentObject )
		for ( auto child : this->_pParentObject->_childObjects )
			if ( child->GetObjectName() == name )
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

void Base::DisplayHierarchy( int level )
{
	cout << string( level * 2, ' ' ) << this->_objectName << endl;

	for ( auto child : this->_childObjects )
		child->DisplayHierarchy( level + 1 );
}

void Base::AddChild( Base* pChild )
{
	this->_childObjects.push_back( pChild );
}
