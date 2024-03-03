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
	for ( Base* child : this->_childObjects )
		delete child;
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

Base* Base::GetChildByName( string name )
{
	for ( auto child : this->_childObjects )
		if ( child->GetObjectName() == name )
			return child;

	return nullptr;
}

void Base::DisplayHierarchy()
{
	if ( this->_childObjects.size() != 0 )
	{
		cout << endl << this->GetObjectName();

		for ( auto elem : this->_childObjects )
		{
			cout << "  " << elem->GetObjectName();
			elem->DisplayHierarchy();
		}
	}

}
