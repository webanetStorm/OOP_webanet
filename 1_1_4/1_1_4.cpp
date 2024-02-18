#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


int main()
{
    char value;
    cin >> value;


    if ( value >= 'A' && value <= 'Z' ) 
        value += 'a' - 'A';

    if ( value >= 'a' && value <= 'z' )
    {
        if ( value == 'a' || value == 'e' || value == 'i' || value == 'o' || value == 'u'  || value == 'y' )
            cout << "vowel";
        else
            cout << "consonant";
    }
    else
        cout << "Not letter";


    return 0;
}
