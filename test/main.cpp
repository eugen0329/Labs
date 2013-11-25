#include <cstdlib>
#include <iostream>
#include <string>

class Mycl {
pubclic:
    int a;
    friend ostream& operetor<< (ostream&, Mycl);
};
using namespace std;

ostream& operetor<< (ostream& outStream, Mycl obj)
{
    outStream << obj.a;
    return ostream;
}
int main()
{
    Mycl obj;
    obj.a = 2;
    cout << obj;
    return 0;
}

