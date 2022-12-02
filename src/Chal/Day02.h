#pragma once
#include "Chal.h"
#include <string>

class Day02 : public Chal{
public:
    virtual std::string Stage1(std::string& input) override;
    virtual std::string Stage2(std::string& input) override;
};
