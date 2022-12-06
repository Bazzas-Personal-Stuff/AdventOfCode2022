#pragma once
#include "Chal.h"
#include <string>

class Day02 : public Chal {
public:
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;
    // virtual std::stringstream GetGivenInput() override {};
    virtual std::stringstream GetGivenInput() override {
        return std::stringstream (R"(A Y
B X
C Z)");
    }
};
