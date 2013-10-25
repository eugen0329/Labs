#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define STRING_SIZE 80

class String
{
public:
    String();
    String(const String&);
    String(const char*);
    ~String();
    String operator=(String);
    String operator+(String);
    String operator+=(String);
    bool   operator==(String);
    char operator[](int);
    void  operator() (int, int);
    friend istream& operator>>(istream&, String&);    
    friend ostream& operator<<(ostream&, String);
 
private:
    char* string;
};

char String::operator[](int index)
{
    if((unsigned)index > strlen(string) - 1)
    {
        cout << "Index greater than the size of the string\n";
        exit(1);
    }
    return string[index];
}

String String::operator+=(String obj2)
{
    if(strlen(string) + strlen(obj2.string) >= STRING_SIZE)
    {
        exit(1);
    }
    strcat(string, obj2.string);
    
    return *this;    
}
istream& operator>>(istream& stream, String& obj)    
{
    stream.getline(obj.string, STRING_SIZE);
    return stream;    
}
 
void String::operator() (int from, int to)               //Выводит символы
{                                                        //строки от from
    if(strlen(string) < (unsigned) from ||               //до to 
       strlen(string) < (unsigned) to || to < from) 
    {
        cout << "Incorrect using of operator ()" << endl;
        exit(1);
    }
    int i;
    String temp;
    for(i = from; i < to ;i++)
    {
        cout << string[i];
    }
    cout << endl;
}

bool String::operator==(String obj2)
{
    if(strcmp(string, obj2.string) ) 
    {
        return false;   
    }
    
    return true;
}

String::String(const String& obj2)
{
    string = new char [STRING_SIZE];
    strcpy(string, obj2.string);
}

String String::operator=(String inputString)
{
    if(strlen(inputString.string) >= STRING_SIZE)
    {
        exit(1);
    }
    strcpy(string, inputString.string);

    return *this;
}

String String::operator+(String obj2)
{
    if(strlen(string) + strlen(obj2.string) >= STRING_SIZE)
    {
        exit(1);
    }
    String temp;
    strcat(temp.string, this->string);
    strcat(temp.string, obj2.string);
    
    return temp;
}
String::String(const char *inputString )
{
    this->string = new char [STRING_SIZE];
    strncpy(this->string, inputString, STRING_SIZE);
}

String::~String()
{
    delete [] string;
}

String::String()
{
    string = new char [STRING_SIZE];
    string[0] = '\0';  
}

ostream& operator <<(ostream& stream, String obj)
{
    stream << obj.string << "\n";
    return stream;
}

int main()
{
    int index;
    String string1("Hello"), string2;
    cout << "The first string is:\n  " << string1 <<"\nEnter the second string:\n  ";
    cin >> string2;
    if (string2 == string1)
    {
        cout << "String are equal\n\n";
    }
    else 
    {
        cout << "Strings are not equal\n\n";
    }
    cout << "The result of string1 + string2:\n  "<< string1 + string2 << '\n';
    cout << "Enter the number of symbol you want to show in string2(from \"0\")\n";
    cin >> index;
    cout << string2[index] << endl;
    cout << "The result of call string(2,4):\n  ";
    string1(2,4);
    cout << "The result of string1 += string 2:\n  ";
    string1 += string2;
    cout << "string1 = " << string1 << "  string2 = " << string2 << endl;
    cout << "The result of string1 = string2:\n  ";
    string1 = string2;
    cout << "string1 = " << string1 << "  string2 = " << string2 << endl;
    return 0;
}

