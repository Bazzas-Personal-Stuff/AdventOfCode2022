#pragma once
#include <string>

class Chal {
public:
    Chal() {}
    virtual std::string Stage1(std::string& input) = 0;
    virtual std::string Stage2(std::string& input) = 0;
};