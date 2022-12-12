#pragma once
#include "Chal.h"
#include <string>

class Day09 : public Chal {    
public:

    int SimulateRope(std::istream& input, int ropeLength);
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;

    virtual std::stringstream GetGivenInput() override {
        return std::stringstream(R"(R 4
U 4
L 3
D 1
R 4
D 1
L 5
R 2
)");
    }

    
};
