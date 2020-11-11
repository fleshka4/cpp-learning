#include <bits/stdc++.h>//12
#include <regex>
#include "partOne.h"
#include "partTwo.h"

int main() {
    std::cout << "Rambo_pro, what do u wanna check, please enter part 1 or 2: ";
    std::string input;
    std::getline(std::cin, input);
    std::regex r1(".*1.*");
    std::regex r2(".*2.*");
    if (std::regex_match(input, r1)) {
        partOne();
    }
    else if (std::regex_match(input, r2)) {
        partTwo();
    }
    return 0;
}