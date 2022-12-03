#include "pch.h"
#include "Day03.h"
#include "gtest/gtest.h"

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
        for(char c : lhs) {
            // convert to priority int
            int priority = (int)c;
            if(priority > 'Z') {
                priority = priority - 'a' + 1;
            }
            else {
                priority = priority - 'A' + 27;
            }

            priorityExistLHS[priority] = true;
        }
        
        vector<bool> priorityExistRHS(53, false); // index 0 is unused
        for(char c : rhs) {
            // convert to priority int
            int priority = (int)c;
            if(priority > 'Z') {
                priority = priority - 'a' + 1;
            }
            else {
                priority = priority - 'A' + 27;
            }

            priorityExistRHS[priority] = true;
        }


        for(int i = 0; i < 53; i++) {
            bool bothExist = priorityExistLHS[i] && priorityExistRHS[i];
            if(bothExist) {
                sum += i;
                break;
            }
        }
        // Find repeated character
        
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
            int priority = (int)c;
            if(priority > 'Z') {
                priority = priority - 'a' + 1;
            }
            else {
                priority = priority - 'A' + 27;
            }
            priorityExistA[priority] = true;
        }
        
        for(char c : inB) {
            int priority = (int)c;
            if(priority > 'Z') {
                priority = priority - 'a' + 1;
            }
            else {
                priority = priority - 'A' + 27;
            }
            priorityExistB[priority] = true;
        }

        for(char c : inC) {
            int priority = (int)c;
            if(priority > 'Z') {
                priority = priority - 'a' + 1;
            }
            else {
                priority = priority - 'A' + 27;
            }
            priorityExistC[priority] = true;
        }

        for(int i = 0; i < priorityExistA.size(); i++) {
            if( priorityExistA[i] &&
                priorityExistB[i] &&
                priorityExistC[i]) {
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
    std::string input(R"(vJrwpWtwJgWrhcsFMMfFFhFp
jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
PmmdzqPrVvPwwTWBwg
wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
ttgJtRGJQctTZtZT
CrZsJsPPZsGzwwsLwLmpwMDw)");

    std::stringstream inputSS(input);
    std::string expected("157");

    ASSERT_EQ(expected, day.Stage1(inputSS));
}

TEST(Day03, Stage2) {
    Day03 day = Day03();
    std::string input(R"(vJrwpWtwJgWrhcsFMMfFFhFp
jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
PmmdzqPrVvPwwTWBwg
wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
ttgJtRGJQctTZtZT
CrZsJsPPZsGzwwsLwLmpwMDw)");

    std::stringstream inputSS(input);
    std::string expected("70");

    ASSERT_EQ(expected, day.Stage2(inputSS));
}
