#pragma once
#include "Chal.h"
#include <string>

class DayTemplate : public Chal{
public:
    virtual std::string Stage1(std::string& input) override;
    virtual std::string Stage2(std::string& input) override;
};
