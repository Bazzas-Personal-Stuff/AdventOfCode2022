#include "pch.h"
#include "Day03.h"
#include "gtest/gtest.h"

std::string Day03::Stage1(std::istream &input) {
    using namespace std;
    stringstream outSS;

    unsigned long sum = 0;
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

            cout << priority << endl;
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

    outSS << "Stage2 not implemented";

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
    std::string expected("Test not implemented");

    ASSERT_EQ(expected, day.Stage2(inputSS));
}
