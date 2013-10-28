#include <cstdlib>
#include <iostream>
#include "string.hpp"
using namespace std;


int main()
{
    String string1, string2, string3;
    cin >> string1;
    cout << string1;
    string2 = string1;
    string2 += string1;
    string2[0] = '2';
    cout << string2;
    string3 = string1 + string2 + "asd" + string2;
    cout << string3;

    return 0;
}
