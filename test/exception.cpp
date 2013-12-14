#include "exception.h"

Exception::Exception(const char* inString, int inExitStaus)
{
    message = inString; 
    exitStatus = inExitStaus;
}

Exception::Exception(const String inString, int inExitStaus)
{
    message = inString; 
    exitStatus = inExitStaus;
}

Exception::Exception()
{
    message = "";
    exitStatus = 0;
}

Exception::~Exception()
{
}

String Exception::getMessage() 
{
    return message;
}

int Exception::getExitStatus() 
{
    return exitStatus;
}
    
BadInput::BadInput(const char* inString, int exitStatus) : Exception(inString, exitStatus)
{
    
}

ArrayOverflow::ArrayOverflow(const char* inString, int exitStatus) : Exception(inString, exitStatus)
{
}

WrongData::WrongData(const char* inString, int exitStatus) : Exception(inString, exitStatus)
{
}

BadInput::BadInput(const BadInput& obj2) : Exception(obj2.message, obj2.exitStatus)
{
}

ArrayOverflow::ArrayOverflow(const ArrayOverflow& obj2) : Exception(obj2.message, obj2.exitStatus)
{
}

WrongData::WrongData(const WrongData& obj2) : Exception(obj2.message, obj2.exitStatus)
{
}
