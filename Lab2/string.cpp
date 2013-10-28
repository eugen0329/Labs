#include "string.hpp"

char& String::operator[](int index)
{
    if((unsigned)index > strlen(string) - 1)
    {
        cout << "Index greater than the size of the string\n";
        exit(1);
    }
    return string[index];
}

String String::operator+=(String inputObject)
{
    char *buffer;
    buffer = new char [size];
    strcpy(buffer, string);
    
    delete [] string;
    size += inputObject.size - 1;
    cout << size;
    string = new char [size];
    cout << strlen(buffer);
    strncpy(string, buffer, strlen(buffer) + 1);
    strcat(string, inputObject.string);
    delete [] buffer;   

    return *this;  
}


String String::operator=(String inputObject)
{
    if(size != inputObject.size)
    {
        delete [] string;
        string = new char [inputObject.size];
    }
    size = inputObject.size;
    strncpy(string, inputObject.string, size);

        
    return *this;
}

//void String::operator() (int from, int to)               //Выводит символы
//{                                                        //строки от from
//    if(strlen(string) < (unsigned) from ||               //до to 
//       strlen(string) > (unsigned) to || to < from) 
//    {
//        cout << "Incorrect using of operator ()" << endl;
//        exit(1);
//    }
//    int i;
//    String temp;
//    for(i = from; i <= to ;i++)
//    {
//        cout << string[i];
//    }
//    cout << endl;
//}

bool String::operator==(String obj2)
{
    if(strcmp(string, obj2.string) ) 
    {
        return false;   
    }
    
    return true;
}



String String::operator+(String obj2)
{
    
    String temp;
    temp.size = size + obj2.size + 1;
    temp.string = new char [temp.size];
    strncpy(temp.string, this->string, size);
    strcat(temp.string, obj2.string);
    
    return temp;
}

String String::operator+(const char* inputString)
{  
    String temp;
    temp.size = size + strlen(inputString);
    temp.string = new char [temp.size];
    strncpy(temp.string, this->string, size);
    strcat(temp.string, inputString);
    return temp;
}

ostream& operator <<(ostream& stream, String obj)
{   
    if(obj.size == 0)
    {
        return stream;
    }
    stream << obj.string << endl;
    return stream;
}


String::String(const String& obj2)
{
    string = new char [obj2.size];
    strcpy(string, obj2.string);
    size = obj2.size;
}

String::~String()
{
    if(size != 0)
    {
        delete [] string;
    }
}

istream& operator>>(istream& stream, String& obj)  
{
    char buffer[STRING_SIZE];
    stream.getline(buffer, STRING_SIZE);

    if(obj.size != 0)
    {
        delete [] obj.string;
    }
    obj.size = strlen(buffer) + 1;
    obj.string = new char [obj.size];
    strcpy(obj.string, buffer); 
    return stream;    
}
 
String::String()
{
    string = NULL;
    size = 0;
}

