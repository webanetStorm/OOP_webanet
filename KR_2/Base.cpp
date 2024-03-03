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
	for ( Base* pChild : this->_childObjects )
		delete pChild;
}

bool Base::SetObjectName( string name )
{
	if ( this->_pParentObject )
		for ( Base* pChild : this->_pParentObject->_childObjects )
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
	for ( Base* pChild : this->_childObjects )
		if ( pChild->GetObjectName() == name )
			return pChild;

	return nullptr;
}

Base* Base::FindOnBranch( string name )
{
	if ( this->_objectName == name ) 
		return this;

	for ( Base* pChild : this->_childObjects )
		if ( Base* found = pChild->FindOnBranch( name ) )
			return found;

	return nullptr;
}

void Base::DisplayHierarchy()
{
	if ( this->_childObjects.size() != 0 )
	{
		cout << endl << this->GetObjectName();

		for ( Base* pChild : this->_childObjects )
		{
			cout << "  " << pChild->GetObjectName();
			pChild->DisplayHierarchy();
		}
	}

}

void Base::TreeTraversal( int level )
{
	cout << endl << string( level * 4, ' ' ) << this->_objectName;

	for ( auto pChild : this->_childObjects )
		pChild->TreeTraversal( level + 1 );
}
