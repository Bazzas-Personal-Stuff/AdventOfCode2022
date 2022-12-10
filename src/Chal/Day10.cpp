#include "pch.h"
#include "Day10.h"
#include "gtest/gtest.h"

std::string Day10::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    int signalStrength = 0;
    int reg = 1;
    int cycleCounter = 0;
    for(string command; input >> command;) {
        cycleCounter++;
        if(cycleCounter == 20 || (cycleCounter + 20) % 40 == 0) {
            signalStrength += cycleCounter * reg;
        }
        
        if(command == "addx") {
            cycleCounter++;
            if(cycleCounter == 20 || (cycleCounter + 20) % 40 == 0) {
                signalStrength += cycleCounter * reg;
            }
            int argument;
            input >> argument;
            reg += argument;
        }
        else {
            // noop
            continue;
        }
    }
    
    outSS << signalStrength;

    return outSS.str();
}

std::string Day10::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;
    
    int reg = 1;
    int cycleCounter = -1;
    for(string command; input >> command;) {
        cycleCounter++;
        if(cycleCounter == 40) {
            outSS << '\n';
            cycleCounter = 0;
        }
        // Check sprite pos at cycle idx
        if(abs(cycleCounter - reg) < 2) {
            outSS << '#';
        }
        else {
            outSS << ' ';
        }
        
        if(command == "addx") {
            cycleCounter++;
            if(cycleCounter == 40) {
                outSS << '\n';
                cycleCounter = 0;
            }
            // Check sprite pos at cycle idx
            if(abs(cycleCounter - reg) < 2) {
                outSS << '#';
            }
            else {
                outSS << ' ';
            }
            int argument;
            input >> argument;
            reg += argument;
        }
        else {
            // noop
            continue;
        }
    }
    
    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day10, Stage1) {
    Day10 day = Day10();

    std::stringstream input = day.GetGivenInput();
    std::string expected("13140");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day10, Stage2) {
    Day10 day = Day10();

    std::stringstream input = day.GetGivenInput();
    std::string expected(R"(##  ##  ##  ##  ##  ##  ##  ##  ##  ##  
###   ###   ###   ###   ###   ###   ### 
####    ####    ####    ####    ####    
#####     #####     #####     #####     
######      ######      ######      ####
#######       #######       #######     )");

    ASSERT_EQ(expected, day.Stage2(input));
}
