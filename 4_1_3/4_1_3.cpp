#include "Class8.h"


int main()
{
	string name;
	cin >> name;

	Class8* pObj = new Class8( name );


	cout << ( (Class1*)( (Class2*)( (Class6*)( pObj ) ) ) )->GetName() << endl;
	cout << ( (Class1*)( (Class3*)( (Class6*)( pObj ) ) ) )->GetName() << endl;

	cout << ( (Class1*)( (Class4*)( (Class7*)( pObj ) ) ) )->GetName() << endl;
	cout << ( (Class1*)( (Class5*)( (Class7*)( pObj ) ) ) )->GetName() << endl;

	cout << ( (Class2*)( (Class6*)( pObj ) ) )->GetName() << endl;
	cout << ( (Class3*)( (Class6*)( pObj ) ) )->GetName() << endl;

	cout << ( (Class4*)( (Class7*)( pObj ) ) )->GetName() << endl;
	cout << ( (Class5*)( (Class7*)( pObj ) ) )->GetName() << endl;

	cout << ( (Class6*)( pObj ) )->GetName() << endl;
	cout << ( (Class7*)( pObj ) )->GetName() << endl;

	cout << pObj->GetName();


	delete pObj;


	return 0;
}
