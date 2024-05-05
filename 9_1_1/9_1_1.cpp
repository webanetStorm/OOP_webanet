#include <vector>
#include "Triangle.h"

using namespace std;


int main()
{
	vector<Triangle> triangles;
	Triangle* pLast = nullptr;
	int n, index1, index2;
	char op;


	cin >> n;

	for ( int i = 0; i < n; i++ )
	{
		int a, b, c;
		cin >> a >> b >> c;

		triangles.push_back( Triangle( a, b, c ) );
	}

	while ( cin >> index1 >> op >> index2 )
	{
		if ( op == '+' )
		{
			triangles[index1 - 1] = triangles[index1 - 1] + triangles[index2 - 1];
		}
		else if ( op == '-' )
		{
			triangles[index1 - 1] = triangles[index1 - 1] - triangles[index2 - 1];
		}

		pLast = &triangles[index1 - 1];
	}

	pLast->Print();


	return 0;
}
