#pragma once
#include "Chal.h"
#include <string>

class Day06 : public Chal {
public:
    static bool HasDuplicates(const std::vector<int>& collection);
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;

    virtual std::stringstream GetGivenInput() override {
        return std::stringstream(R"(mjqjpqmgbljsphdztnvjfqwrcgsmlb)");
    }

    
};
