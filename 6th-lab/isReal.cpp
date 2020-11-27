#include <iostream>
#include <fstream>
#include "isReal.h"



bool isFloatingPoint(std::string str)
{
    if (isSign(str[0]))
    {
        str.erase(0, 1);
    }
    int e = str.find('E', 0);
    if (e != -1 && isMantissa(str.substr(0, e)) && isOrder(str.substr(e + 1, str.length() - e)))
    {
        return true;
    }
    return false;
}
 
bool isMantissa(std::string str)
{
    int point = str.find('.', 0);
    if (point != -1 && isInteger(str.substr(0, point)) && isInteger(str.substr(point + 1, str.length() - point)))
    {
        return true;
    }
    return false;
}
 
bool isOrder(std::string str)
{
    if (isSign(str[0]))
    {
        str.erase(0, 1);
    }
    if (isInteger(str))
    {
        return true;
    }
    return false;
}
 
bool isInteger(std::string str)
{
    if (str.empty())
    {
        return true;
    }
    if (isDigit(str[0]) && isInteger(str.erase(0, 1)))
    {
        return true;
    }
    return false;
}
 
bool isDigit(const char ch)
{
    if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4'
        || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
    {
        return true;
    }
    return false;
}
 
bool isSign(const char ch)
{
    if (ch == '-' || ch == '+')
    {
        return true;
    }
    return false;
}
 
std::string openNewString(const std::string& path)
{
    static int alreadyRead = 0;
    std::ifstream in;
    std::string str = "";
    in.open(path, std::ios::in);
 
    skipStrings(in, alreadyRead);
 
    getline(in, str, '\n');
    if (str.empty())
    {
        throw StrException();
    }
 
    alreadyRead++;
    in.close();
    return str;
}
 
void skipStrings(std::ifstream& in, int n)
{
    for (int i = 0; i < n; i++)
    {
        do {
            in.ignore(10000, '\n');
        } while (in.gcount() == 10000);
    }
}