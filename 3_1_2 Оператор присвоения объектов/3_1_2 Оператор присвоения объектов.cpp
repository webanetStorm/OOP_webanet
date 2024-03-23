#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Array.h"

using namespace std;


int main()
{
	int n, m; 
	cin >> n >> m; 
	

	if ( n <= 4 )
	{
		cout << n << '?'; return 1;
	}
	else if ( m <= 4 )
	{
		cout << m << '?'; return 1;
	}
	
	Array a( n ), b( m ); 
	
	int* temp = a.GetArray(); 
	a = b; a.SetArray( temp ); 
	a.Print(); b.Print(); 
	
	
	return 0;
}
