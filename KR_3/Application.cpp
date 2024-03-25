#include "Application.h"
#include <iostream>


Application::Application( Base* pParentObject ) : Base( pParentObject ) {}

void Application::BuildTreeObjects()
{
	Base *pParentObject = this;
	string parentPath, childName;
	int classNumber;


	cin >> parentPath;
	this->SetObjectName( parentPath );

	while ( true )
	{
		cin >> parentPath;

		if ( parentPath == "endtree" )
			break;


		cin >> childName >> classNumber;

		pParentObject = this->FindObjectByPath( parentPath );

		if ( pParentObject && pParentObject->GetChildByName( childName ) == nullptr )
		{
			switch ( classNumber )
			{
				case 2:
					new Class2( pParentObject, childName );
					break;
				case 3:
					new Class3( pParentObject, childName );
					break;
				case 4:
					new Class4( pParentObject, childName );
					break;
				case 5:
					new Class5( pParentObject, childName );
					break;
				case 6:
					new Class6( pParentObject, childName );
					break;
			}
		}
	}
	

	cout << "Object tree";
	this->DisplayHierarchy();

	Base *pCurrentObject = this, *pObj;
	string command, parameter;

	while ( cin >> command >> parameter )
	{
		if ( command == "SET" )
		{
			if ( pObj = this->FindObjectByPath( parameter ) )
			{
				pCurrentObject = pObj;
				cout << "Object is set: " << pCurrentObject->GetObjectName() << endl;
			}
			else
			{
				cout << "The object was not found at the specified coordinate: " << parameter << endl;
			}
		}
		//else if ( command == "FIND" )
		//{
		//	( pObj = pCurrentObject->FindObjectByPath( parameter ) )
		//		? cout << parameter << "     Object name: " << pObj->GetObjectName() << endl
		//		: cout << parameter << "     Object is not found" << endl;
		//}
		//else if ( command == "MOVE" )
		//{
		//	pCurrentObject->SetNewParent( pObj = pCurrentObject->FindObjectByPath( parameter ) )
		//		? cout << "New head object: " << pObj->GetObjectName() << endl
		//		: cout << "Redefining the head object failed" << endl;
		//}
		//else if ( command == "DELETE" )
		//{
		//	pCurrentObject->DeleteChildByName( parameter );
		//	cout << "The object " << parameter << " has been deleted" << endl;
		//}
		else if ( command == "END" )
		{
			break;
		}
	}
}

int Application::ExecApp()
{
	cout << "Object tree";

	this->DisplayHierarchy();

	return 0;
}
