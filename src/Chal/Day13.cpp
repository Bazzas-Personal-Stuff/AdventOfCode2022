#include "pch.h"
#include "Day13.h"
#include "gtest/gtest.h"

std::string Day13::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    string lineA;
    string lineB;
    while(input >> lineA >> lineB) {
        for(int i = 0, j = 0; i < lineA.size() && j < lineB.size(); i++, j++) {
            
        }
    }
    
    outSS << "Stage1 not implemented";

    return outSS.str();
}

std::string Day13::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;

    outSS << "Stage2 not implemented";

    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day13, Stage1) {
    Day13 day = Day13();

    std::stringstream input = day.GetGivenInput();
    std::string expected("13");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day13, Stage2) {
    Day13 day = Day13();

    std::stringstream input = day.GetGivenInput();
    std::string expected("Test not implemented");

    ASSERT_EQ(expected, day.Stage2(input));
}
