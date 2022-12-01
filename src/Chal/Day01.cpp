#include "pch.h"
#include "Day01.h"
#include "gtest/gtest.h"

std::string Day01::Stage1(std::string& input) {

    return input;
}

std::string Day01::Stage2(std::string& input) {
    
    return input;
}

TEST(Day01Test, Stage1) {
    Day01 day = Day01();
    
    std::string input("1");
    std::string expected("1");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day01Test, Stage2) {
    Day01 day = Day01();
    
    std::string input("2");
    std::string expected("2");

    ASSERT_EQ(expected, day.Stage2(input));
}


