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
	cout << endl;

	
	Base *pCurrentObject = this, *pObj = this;
	string command, parameter;

	while ( cin >> command )
	{

		if ( command == "SET" )
		{
			cin >> parameter;

			if ( pObj = pCurrentObject->FindObjectByPath( parameter ) )
			{
				pCurrentObject = pObj;
				cout << "Object is set: " << pCurrentObject->GetObjectName() << endl;
			}
			else
			{
				cout << "The object was not found at the specified coordinate: " << parameter << endl;
			}
		}
		else if ( command == "FIND" )
		{
			cin >> parameter;

			( pObj = pCurrentObject->FindObjectByPath( parameter ) )
				? cout << parameter << "     Object name: " << pObj->GetObjectName() << endl
				: cout << parameter << "     Object is not found" << endl;
		}
		else if ( command == "MOVE" )
		{
			cin >> parameter;

			pCurrentObject->SetNewParent( pCurrentObject->FindObjectByPath( parameter ), parameter );
		}
		else if ( command == "DELETE" )
		{
			cin >> parameter;

			pCurrentObject->DeleteChildByName( parameter );
			cout << "The object " << parameter << " has been deleted" << endl;
		}
		else if ( command == "END" )
		{
			break;
		}

	}
}

int Application::ExecApp()
{
	cout << "Current object hierarchy tree";

	this->DisplayHierarchy();

	return 0;
}
