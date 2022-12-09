#include "pch.h"
#include "Day09.h"
#include "gtest/gtest.h"


std::string Day09::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;
    
    unordered_set<pair<int, int>, pair_hash> visited;
    visited.insert({0, 0});
    int headPosX = 0;
    int headPosY = 0;
    int tailPosX = 0;
    int tailPosY = 0;

    char direction;
    int distance;
    while(input >> direction >> distance) {
        int headMoveX = 0;
        int headMoveY = 0;
        switch (direction) {
        case 'U':
            headMoveY = 1;
            break;
        case 'D':
            headMoveY = -1;
            break;
        case 'R':
            headMoveX = 1;
            break;
        case 'L':
            headMoveX = -1;
            break;
        default:
            cout << "Unrecognized movement command" << endl;
        }
        
        for(int i = 0; i < distance; i++) {
            // Move head
            headPosX += headMoveX;
            headPosY += headMoveY;
            // Move tail
            // Get tail offset magnitude
            bool shouldTailMove = abs(headPosX - tailPosX) >= 2 ||
                abs(headPosY - tailPosY) >= 2;
            if(shouldTailMove) {
                // get tail move direction
                int tailMoveX = 0;
                int tailMoveY = 0;
                if(headPosX > tailPosX) {
                    tailMoveX = 1;
                }
                if(headPosX < tailPosX) {
                    tailMoveX = -1;
                }
                if(headPosY > tailPosY) {
                    tailMoveY = 1;
                }
                if(headPosY < tailPosY) {
                    tailMoveY = -1;
                }

                tailPosX += tailMoveX;
                tailPosY += tailMoveY;
                
                // insert tail position
                visited.insert({tailPosX, tailPosY});
            }
            
        }
    }
    outSS << visited.size();
    return outSS.str();
}

std::string Day09::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;
    
    unordered_set<pair<int, int>, pair_hash> visited;
    visited.insert({0, 0});
    pair<int, int> headPos(0, 0);
    pair<int, int> tailPos(0, 0);

    char direction;
    int distance;
    while(input >> direction >> distance) {
        int headMoveX = 0;
        int headMoveY = 0;
        switch (direction) {
        case 'U':
            headMoveY = 1;
            break;
        case 'D':
            headMoveY = -1;
            break;
        case 'R':
            headMoveX = 1;
            break;
        case 'L':
            headMoveX = -1;
            break;
        default:
            cout << "Unrecognized movement command" << endl;
        }
        
        for(int i = 0; i < distance; i++) {
            // Move head
            headPos.first += headMoveX;
            headPos.second += headMoveY;
            // Move tail
// ===========================================================================
            // TODO: Add vector of intermediate knots
// ===========================================================================
            
            // Get tail offset magnitude
            bool shouldTailMove = abs(headPos.first - tailPos.first) >= 2 ||
                abs(headPos.second - tailPos.second) >= 2;
            if(shouldTailMove) {
                // get tail move direction
                int tailMoveX = 0;
                int tailMoveY = 0;
                if(headPos.first > tailPos.first) {
                    tailMoveX = 1;
                }
                if(headPos.first < tailPos.first) {
                    tailMoveX = -1;
                }
                if(headPos.second > tailPos.second) {
                    tailMoveY = 1;
                }
                if(headPos.second < tailPos.second) {
                    tailMoveY = -1;
                }

                tailPos.first += tailMoveX;
                tailPos.second += tailMoveY;
                
                // insert tail position
                visited.insert({tailPos});
            }
            
        }
    }
    outSS << visited.size();
    return outSS.str();

}


// =============== gtests for given cases ===============

TEST(Day09, Stage1) {
    Day09 day = Day09();

    std::stringstream input = day.GetGivenInput();
    std::string expected("13");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day09, Stage2) {
    Day09 day = Day09();

    std::stringstream input = day.GetGivenInput();
    std::string expected("36");

    ASSERT_EQ(expected, day.Stage2(input));
}
