#pragma once
#include "Chal.h"
#include <string>

class Day01 : public Chal{
public:
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;
    
    virtual std::stringstream GetGivenInput() override {
        return std::stringstream (R"(1000
    2000
    3000

    4000

    5000
    6000

    7000
    8000
    9000

    10000)");
    }
};
