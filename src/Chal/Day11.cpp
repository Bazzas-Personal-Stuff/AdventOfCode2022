#include "pch.h"
#include "Day11.h"
#include "gtest/gtest.h"

std::string Day11::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    outSS << "Stage1 not implemented";

    return outSS.str();
}

std::string Day11::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;

    outSS << "Stage2 not implemented";

    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day11, Stage1) {
    Day11 day = Day11();

    std::stringstream input = day.GetGivenInput();
    std::string expected("Test not implemented");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day11, Stage2) {
    Day11 day = Day11();

    std::stringstream input = day.GetGivenInput();
    std::string expected("Test not implemented");

    ASSERT_EQ(expected, day.Stage2(input));
}
