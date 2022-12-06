#pragma once
#include "Chal.h"
#include <string>

class Day05 : public Chal {
public:
    std::vector<std::deque<char>> ParseCargo(std::istream& input);
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;
    virtual std::stringstream GetGivenInput() override {
        return std::stringstream(R"(    [D]    
[N] [C]    
[Z] [M] [P]
 1   2   3 

move 1 from 2 to 1
move 3 from 1 to 3
move 2 from 2 to 1
move 1 from 1 to 2)");
    }
    
};
