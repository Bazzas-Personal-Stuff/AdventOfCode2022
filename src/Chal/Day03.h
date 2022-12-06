#pragma once
#include "Chal.h"
#include <string>

class Day03 : public Chal {
public:
    static int GetPriority(char c);
    virtual std::string Stage1(std::istream &input) override;
    virtual std::string Stage2(std::istream &input) override;
    // virtual std::stringstream GetGivenInput() override {};
    virtual std::stringstream GetGivenInput() override {
        return std::stringstream (R"(vJrwpWtwJgWrhcsFMMfFFhFp
jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
PmmdzqPrVvPwwTWBwg
wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
ttgJtRGJQctTZtZT
CrZsJsPPZsGzwwsLwLmpwMDw)");
    }

};
