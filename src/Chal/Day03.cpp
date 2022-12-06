#include "pch.h"
#include "Day03.h"
#include "gtest/gtest.h"

int Day03::GetPriority(char c) {
    int priority = c;
    if(priority > 'Z') {
        priority = priority - 'a' + 1;
    }
    else {
        priority = priority - 'A' + 27;
    }
    return priority;
}


std::string Day03::Stage1(std::istream &input) {
    using namespace std;
    stringstream outSS;

    int sum = 0;
    for(string line; input >> line; ) {
        // Split line in half
        int halfLength = line.size() / 2;
        string lhs = line.substr(0, halfLength);
        string rhs = line.substr(halfLength, halfLength);
        
        vector<bool> priorityExistLHS(53, false); // index 0 is unused
        vector<bool> priorityExistRHS(53, false); // index 0 is unused

        for(char c : lhs) {
            priorityExistLHS[GetPriority(c)] = true;
        }
        
        for(char c : rhs) {
            priorityExistRHS[GetPriority(c)] = true;
        }

        // Get matching priority
        for(int i = 0; i < priorityExistLHS.size(); i++) {
            if(priorityExistLHS[i] && priorityExistRHS[i]) {
                sum += i;
                break;
            }
        }
    }
    
    outSS << sum;
    return outSS.str();
}


std::string Day03::Stage2(std::istream &input) {
    using namespace std;
    stringstream outSS;

    int sum = 0;
    for(string inA, inB, inC; input >> inA >> inB >> inC;) {
        
        vector<bool> priorityExistA(53, false); // index 0 is unused
        vector<bool> priorityExistB(53, false); // index 0 is unused
        vector<bool> priorityExistC(53, false); // index 0 is unused
        
        for(char c : inA) {
            priorityExistA[GetPriority(c)] = true;
        }
        
        for(char c : inB) {
            priorityExistB[GetPriority(c)] = true;
        }

        for(char c : inC) {
            priorityExistC[GetPriority(c)] = true;
        }

        for(int i = 0; i < priorityExistA.size(); i++) {
            if( priorityExistA[i] && priorityExistB[i] && priorityExistC[i]) {
                sum += i;
                break;
            }
        }
    }
    
    outSS << sum;
    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day03, Stage1) {
    Day03 day = Day03();

    std::stringstream input = day.GetGivenInput();
    std::string expected("157");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day03, Stage2) {
    Day03 day = Day03();
    
    std::stringstream input = day.GetGivenInput();
    std::string expected("70");

    ASSERT_EQ(expected, day.Stage2(input));
}
