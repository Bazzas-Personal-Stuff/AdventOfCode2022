﻿#include "pch.h"
#include "Day02.h"
#include "gtest/gtest.h"


std::string Day02::Stage1(std::string& input) {
    using namespace std;
    stringstream ss(input);
    stringstream outSS;

    // payoff[opponent][self]
    int payoffTable[3][3] = {
        /*        X      Y       Z   */
        /* A */ {1+3,   2+6,    3+0},
        /* B */ {1+0,   2+3,    3+6},
        /* C */ {1+6,   2+0,    3+3},
    };

    
    int totalScore = 0;
    while(ss.rdbuf()->in_avail() > 2) {
        char opponent, self;
        ss >> opponent >> self;

        int opponentIdx = opponent - 'A';
        int selfIdx = self - 'X';

        int thisScore = payoffTable[opponentIdx][selfIdx];
        totalScore += thisScore;
    }
    
    outSS << totalScore;
    return outSS.str();
}

std::string Day02::Stage2(std::string& input) {
    using namespace std;
    stringstream ss(input);
    stringstream outSS;

    // Change payoff table according to new rules
    // payoff[opponent][self]
    int payoffTable[3][3] = {
        /*        X      Y       Z   */
        /* A */ {0+3,   3+1,    6+2},
        /* B */ {0+1,   3+2,    6+3},
        /* C */ {0+2,   3+3,    6+1},
    };

    
    int totalScore = 0;
    while(ss.rdbuf()->in_avail() > 2) {
        char opponent, self;
        ss >> opponent >> self;

        int opponentIdx = opponent - 'A';
        int selfIdx = self - 'X';

        int thisScore = payoffTable[opponentIdx][selfIdx];
        totalScore += thisScore;
    }
    
    outSS << totalScore;
    return outSS.str();
}

TEST(Day02, Stage1) {
    Day02 day = Day02();
    
    std::string input(R"(A Y
B X
C Z)");
    std::string expected(R"(15)");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day02, Stage2) {
    Day02 day = Day02();
    
    std::string input(R"(A Y
B X
C Z)");
    std::string expected(R"(12)");

    ASSERT_EQ(expected, day.Stage2(input));
}


