#include <iostream>
#include "ArrayHandler.h"

using namespace std;


int main()
{
    int size;
    cin >> size;


    ArrayHandler ah( size );


    ah.ReadArray();

    ah.PrintArraySize();
    cout << endl;

    ah.PrintArray();
    cout << endl;

    ah.ReverseArray();
    ah.PrintArray();


    return 0;
}
