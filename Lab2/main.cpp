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
    void show();
    String operator=(String);
    String operator+(String);
    String operator+=(String);
    bool   operator==(String);
    String  operator() (const char *);
    friend String operator+(int, String);
    friend istream& operator>>(istream&, String&);    
    friend ostream& operator<<(ostream&, String);
 
    char* getString();
private:
    char* string;
};

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

String String::operator() (const char* inputString)
{
    if(strlen(string) + strlen(inputString) >= STRING_SIZE)
    {
        exit(1);
    }
    String temp;
    strcat(temp.string, this->string);
    strcat(temp.string, inputString);
    
    return temp;

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

void String::show()
{
    cout << string << "\n";
}

char* String::getString()
{
    return string;
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
    String string1("Hello"), string2("Hello"), string3;
    //string2 = string2 + string1;
    string2.show();
    cin >> string3;
    cout << string3;
    if (string3 == string1)
    {
        cout << "String are equal\n";
    }
    else 
    {
        cout << "Strings are not equal\n";
    }
    return 0;
}

