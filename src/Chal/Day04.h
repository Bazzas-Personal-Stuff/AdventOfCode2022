#pragma once
#include "Chal.h"
#include <string>

class Day04 : public Chal {
public:
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;
    // virtual std::stringstream GetGivenInput() override {};
    virtual std::stringstream GetGivenInput() override {
        return std::stringstream(R"(2-4,6-8
2-3,4-5
5-7,7-9
2-8,3-7
6-6,4-6
2-6,4-8)");
    }

};
