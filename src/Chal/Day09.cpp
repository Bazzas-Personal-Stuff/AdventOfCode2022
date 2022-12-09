#include "pch.h"
#include "Day09.h"
#include "gtest/gtest.h"

int Day09::SimulateRope(std::istream& input, int ropeLength) {
    using namespace std;
    
    unordered_set<pair<int, int>, pair_hash> visited;
    visited.insert({0, 0});
    vector<pair<int, int>> knots(ropeLength, {0, 0});

    char direction;
    int distance;
    while(input >> direction >> distance) {
        pair<int, int> headMove;
        switch (direction) {
        case 'U':
            headMove.second = 1;
            break;
        case 'D':
            headMove.second = -1;
            break;
        case 'R':
            headMove.first = 1;
            break;
        case 'L':
            headMove.first = -1;
            break;
        default:
            cout << "Unrecognized movement command" << endl;
        }
        
        for(int i = 0; i < distance; i++) {
            // Move head
            knots[0].first += headMove.first;
            knots[0].second += headMove.second;

            // Move the rest of the rope
            for(int j = 1; j < knots.size(); j++) {
                bool shouldThisKnotMove = abs(knots[j-1].first - knots[j].first) >= 2 ||
                    abs(knots[j-1].second - knots[j].second) >= 2;
                
                // Get tail offset magnitude
                if(shouldThisKnotMove) {
                    // get tail move direction
                    pair<int, int> tailMove;
                    if(knots[j-1].first > knots[j].first) {
                        tailMove.first = 1;
                    }
                    if(knots[j-1].first < knots[j].first) {
                        tailMove.first = -1;
                    }
                    if(knots[j-1].second > knots[j].second) {
                        tailMove.second = 1;
                    }
                    if(knots[j-1].second < knots[j].second) {
                        tailMove.second = -1;
                    }

                    knots[j].first += tailMove.first;
                    knots[j].second += tailMove.second;
                }
                else {
                    break;
                }
            }
            // insert tail position
            visited.insert(knots[knots.size()-1]);
        }
    }
    return (int)visited.size();
}


std::string Day09::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    outSS << SimulateRope(input, 2);
    return outSS.str();
}

std::string Day09::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;

    outSS << SimulateRope(input, 10);
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

    // std::stringstream input = day.GetGivenInput();
    std::stringstream input(R"(R 5
U 8
L 8
D 3
R 17
D 10
L 25
U 20)");
    std::string expected("36");

    ASSERT_EQ(expected, day.Stage2(input));
}
