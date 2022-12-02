#include "pch.h"
#include "Day03.h"
#include "gtest/gtest.h"

std::string Day03::Stage1(std::istream &input) {
    using namespace std;
    stringstream outSS;

    outSS << "Stage1 not implemented";

    return outSS.str();
}

std::string Day03::Stage2(std::istream &input) {
    using namespace std;
    stringstream outSS;

    outSS << "Stage2 not implemented";

    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day03, Stage1) {
    Day03 day = Day03();
    std::string input(R"()");

    std::stringstream inputSS(input);
    std::string expected("Test not implemented");

    ASSERT_EQ(expected, day.Stage1(inputSS));
}

TEST(Day03, Stage2) {
    Day03 day = Day03();
    std::string input(R"()");

    std::stringstream inputSS(input);
    std::string expected("Test not implemented");

    ASSERT_EQ(expected, day.Stage2(inputSS));
}
