﻿#pragma once
#include "Chal.h"
#include <string>

class Day01 : public Chal{
public:
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;
};
