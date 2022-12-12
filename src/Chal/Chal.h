#pragma once
#include <string>

class Chal {
public:
    Chal() = default;
    virtual std::string Stage1(std::istream& input) = 0;
    virtual std::string Stage2(std::istream& input) = 0;
    virtual std::stringstream GetGivenInput() = 0;
};