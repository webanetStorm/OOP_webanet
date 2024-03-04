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

void Base::DisplayHierarchy()
{
	if ( this->_childObjects.size() != 0 )
	{
		cout << endl << this->GetObjectName();

		for ( auto pChild : this->_childObjects )
		{
			cout << "  " << pChild->GetObjectName();
			pChild->DisplayHierarchy();
		}
	}

}
