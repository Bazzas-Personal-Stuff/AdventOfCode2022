#include "pch.h"
#include "Day01.h"
#include "gtest/gtest.h"

std::string Day01::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    int maxCal = 0;
    int curCal = 0;
    while(input) {
        string cal;
        getline(input, cal);

        if(cal.empty()) {
            if(curCal > maxCal) {
                maxCal = curCal;
            }
            curCal = 0;
        }
        else {
            curCal += atoi(cal.c_str());
        }
    }
    
    outSS << maxCal;
    
    return outSS.str();
}

std::string Day01::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;

    int maxCals[3] = {0, 0, 0}; // [0] is smallest
    int curCal = 0;
    while(input) {
        string cal;
        getline(input, cal);

        if(cal.empty()) {
            // bubble sort
            int temp;
            if( maxCals[0] > maxCals[1]) {
                temp = maxCals[0];
                maxCals[0] = maxCals[1];
                maxCals[1] = temp;
            }
            if( maxCals[1] > maxCals[2]) {
                temp = maxCals[1];
                maxCals[1] = maxCals[2];
                maxCals[2] = temp;
            }
            if( maxCals[0] > maxCals[1]) {
                temp = maxCals[0];
                maxCals[0] = maxCals[1];
                maxCals[1] = temp;
            }
            
            // replace smallest
            if(curCal > maxCals[0]) {
                maxCals[0] = curCal;
            }
            curCal = 0;
        }
        else {
            curCal += atoi(cal.c_str());
        }
    }

    int totalCal = 0;
    for(int i = 0; i < 3; i++) {
        totalCal += maxCals[i];
    }
    outSS << totalCal;
    
    return outSS.str();
}

TEST(Day01Test, Stage1) {
    Day01 day = Day01();
    std::stringstream input = day.GetGivenInput();

    std::string expected("24000");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day01Test, Stage2) {
    Day01 day = Day01();
    std::stringstream input = day.GetGivenInput();

    std::string expected("45000");

    ASSERT_EQ(expected, day.Stage2(input));
}


