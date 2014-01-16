#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include "string.h"

class Exception {
public:
    Exception(const char*, int);
    Exception(const String, int);
    Exception();
    virtual String getMessage();
    virtual int getExitStatus();
    virtual ~Exception();
protected:
    String message;
    int exitStatus;
};

class BadInput : public Exception {
public:
    BadInput(const char* inString, int exitStatus = 1); 
    BadInput(const BadInput&);
};

class ArrayOverflow : public Exception {
public:
    ArrayOverflow(const char* inString, int exitStatus = 2); 
    ArrayOverflow(const ArrayOverflow&);
};

class WrongData : public Exception {
public:
    WrongData(const char* inString, int exitStatus = 3); 
    WrongData(const WrongData&);
};

#endif
