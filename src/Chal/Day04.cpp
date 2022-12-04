#include "pch.h"
#include "Day04.h"
#include "gtest/gtest.h"

std::string Day04::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    int numOverlaps = 0;

    for(string aLowStr; std::getline(input, aLowStr, '-');) {
        string aHighStr, bLowStr, bHighStr;
        std::getline(input, aHighStr, ',');
        std::getline(input, bLowStr, '-');
        std::getline(input, bHighStr);

        // Parse to int
        int aLow = stoi(aLowStr);
        int aHigh = stoi(aHighStr);
        int bLow = stoi(bLowStr);
        int bHigh = stoi(bHighStr);

        if(aLow <= bLow && aHigh >= bHigh ||
            bLow <= aLow && bHigh >= aHigh) {
            numOverlaps++;
        }
    }
    
    outSS << numOverlaps;
    return outSS.str();
}

std::string Day04::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;

    int numOverlaps = 0;

    for(string aLowStr; std::getline(input, aLowStr, '-');) {
        string aHighStr, bLowStr, bHighStr;
        std::getline(input, aHighStr, ',');
        std::getline(input, bLowStr, '-');
        std::getline(input, bHighStr);

        // Parse to int
        int aLow = stoi(aLowStr);
        int aHigh = stoi(aHighStr);
        int bLow = stoi(bLowStr);
        int bHigh = stoi(bHighStr);

        // Easier to find out if they're not overlapping, then negate
        if(!(aLow > bHigh && aHigh > bHigh ||
            aLow < bLow && aHigh < bLow)) {
            numOverlaps++;
        }
    }
    
    outSS << numOverlaps;
    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day04, Stage1) {
    Day04 day = Day04();
    std::string input(R"(2-4,6-8
2-3,4-5
5-7,7-9
2-8,3-7
6-6,4-6
2-6,4-8)");

    std::stringstream inputSS(input);
    std::string expected("2");

    ASSERT_EQ(expected, day.Stage1(inputSS));
}

TEST(Day04, Stage2) {
    Day04 day = Day04();
    std::string input(R"(2-4,6-8
2-3,4-5
5-7,7-9
2-8,3-7
6-6,4-6
2-6,4-8)");

    std::stringstream inputSS(input);
    std::string expected("4");

    ASSERT_EQ(expected, day.Stage2(inputSS));
}
