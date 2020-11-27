#ifndef ISREAL_H
#define ISREAL_H
#include <iostream>

class StrException
{
private:
    const std::string s_error = "Считаны все строки";
public:
    StrException()
    {
        
    }
    const char* getError()
    {
        return s_error.c_str();
    }
};


bool isFloatingPoint(std::string str);

bool isMantissa(std::string str);

bool isOrder(std::string str);

bool isInteger(std::string str);

bool isDigit(const char ch);

bool isSign(const char ch);

std::string openNewString(const std::string& path);

void skipStrings(std::ifstream& in, int n);

#endif