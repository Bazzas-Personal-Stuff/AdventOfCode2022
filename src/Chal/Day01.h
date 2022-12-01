#pragma once
#include "Chal.h"
#include <string>

class Day01 : public Chal{
// class Day01 {
public:
    virtual std::string Stage1(std::string& input) override;
    virtual std::string Stage2(std::string& input) override;
    // std::string Stage1(const std::string& input);
    // std::string Stage2(const std::string& input);
};
