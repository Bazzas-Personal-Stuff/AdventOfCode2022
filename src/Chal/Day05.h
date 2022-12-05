#pragma once
#include "Chal.h"
#include <string>

class Day05 : public Chal {
public:
    std::vector<std::deque<char>> ParseCargo(std::istream& input);
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;
    
};
