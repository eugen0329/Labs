#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define STRING_SIZE 80

class String
{
public:
    explicit String();
    String(const String&);
    ~String();
    String operator=(String);
    String operator+(String);
    String operator+(const char*);
    String operator+=(String);
    bool   operator==(String);
    char& operator[](int);
    void  operator() (int, int);
    friend istream& operator>>(istream&, String&);    
    friend ostream& operator<<(ostream&, String);
 
private:
    char* string;
    int size;
};



#endif
