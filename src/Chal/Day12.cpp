#include "pch.h"
#include "Day12.h"
#include "UtilHash.h"

#include <queue>
#include <wnnc.h>

#include "gtest/gtest.h"

bool Day12::Priority::operator()(const Coords& a, const Coords& b) const {
    return a.weight > b.weight;
}

int Day12::GetPriority(std::pair<int, int> fromPoint, std::pair<int, int> toPoint, std::function<int(std::pair<int, int>, std::pair<int, int>)> Heuristic) {
    return PathCosts[fromPoint] +  Heuristic(fromPoint, toPoint);
}

int Day12::Manhattan(std::pair<int, int> fromPoint, std::pair<int, int> toPoint){
    return abs(toPoint.first - fromPoint.first) + abs(toPoint.second - fromPoint.second);
}

void Day12::CheckPosition(std::pair<int, int> checkPos, std::pair<int, int> currentPos, std::function<int(std::pair<int, int>, std::pair<int, int>)> Heuristic) {
    char currentHeight = HeightMap[currentPos.first][currentPos.second];
    int newCost = PathCosts[currentPos] + 1;
    if(checkPos.first < HeightMap.size()) {
        if(HeightMap[checkPos.first][checkPos.second] - currentHeight >= -1
            && (!PathCosts.contains(checkPos)
                || PathCosts[checkPos] > newCost)) {
            PathParents[checkPos] = currentPos;
            PathCosts[checkPos] = newCost;
            Coords newCoords {checkPos, GetPriority(checkPos, EndPos, Heuristic)};
            // Coords newCoords {checkPos, Manhattan(checkPos, EndPos)};
            Frontier.push(newCoords);
            
        }
    }
}

int Day12::Pathfind(std::istream& input, std::function<bool(std::pair<int,int>, std::pair<int, int>)> TargetCheck, std::function<int(std::pair<int, int>, std::pair<int, int>)> Heuristic) {
    using namespace std;

    // Parse heightmap
    HeightMap.clear();
    string line;
    for(int row = 0; input >> line; row++) {
        vector<char>& rowVec = HeightMap.emplace_back();
        for(int col = 0; col < line.size(); col++) {
            if(line[col] == 'S') {
                EndPos = {row, col};
                rowVec.push_back('a');
            }
            else if (line[col] == 'E') {
                StartPos = {row, col};  
                rowVec.push_back('z');
            }
            else {
                rowVec.push_back(line[col]);
            }
        }
    }

    // Pathfinding
    Frontier = priority_queue<Coords, vector<Coords>, Priority>();
    PathParents.clear();
    PathCosts.clear();
    Frontier.push({StartPos, 0});
    PathCosts[StartPos] = 0;
    PathParents[StartPos] = StartPos;

    
    while(!Frontier.empty()) {
        Coords currentCoords = Frontier.top();
        Frontier.pop();
        
        if(TargetCheck(currentCoords.pos, EndPos)) {
            EndPos = currentCoords.pos;
            cout << "Found target" << endl;
            break;
        }
        
        // south
        CheckPosition({currentCoords.pos.first + 1, currentCoords.pos.second}, currentCoords.pos, Heuristic);
        // north
        CheckPosition({currentCoords.pos.first - 1, currentCoords.pos.second}, currentCoords.pos, Heuristic);
        // west
        CheckPosition({currentCoords.pos.first, currentCoords.pos.second + 1}, currentCoords.pos, Heuristic);
        // east
        CheckPosition({currentCoords.pos.first, currentCoords.pos.second - 1}, currentCoords.pos, Heuristic);
    }

    
    // DIAGRAM /////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unordered_map<pair<int, int>, char, pair_hash> directions;
    // int pathLength = 0;
    pair<int, int> currentPos = EndPos;
    cout << "Path: " << endl;
    while(currentPos != StartPos) {
        pair<int, int> nextPos = PathParents[currentPos];
        if(nextPos.first > currentPos.first) {
            directions[nextPos] = '^';
        }
        else if(nextPos.first < currentPos.first) {
            directions[nextPos] = 'V';
        }
        else if(nextPos.second > currentPos.second) {
            directions[nextPos] = '<';
        }
        else {
            directions[nextPos] = '>';
        }
        
        currentPos = nextPos;
    }
    
    for(int row = 0; row < HeightMap.size(); row++) {
        for(int col = 0; col < HeightMap[0].size(); col++) {
            if(directions.contains({row, col})) {
                cout << directions[{row, col}];
            }
            else {
                cout << HeightMap[row][col];
            }
        }
        cout << endl;
    }

    return PathCosts[EndPos];
}

std::string Day12::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    outSS << Pathfind(input,
        [](pair<int, int> currentPos, pair<int, int> targetPos){return currentPos == targetPos;},
      &Manhattan);

            // HeightMap[checkPos.first][checkPos.second] - currentHeight <= 1  
    return outSS.str();
}

std::string Day12::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;

    outSS << Pathfind(input,
        [this](pair<int, int> currentPos, pair<int, int> targetPos) {return HeightMap[currentPos.first][currentPos.second] == 'a';},
        [this](pair<int, int> pos, pair<int, int> target){ return PathCosts[pos];});

    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day12, Stage1) {
    Day12 day = Day12();

    std::stringstream input = day.GetGivenInput();
    std::string expected("31");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day12, Stage2) {
    Day12 day = Day12();

    std::stringstream input = day.GetGivenInput();
    std::string expected("29");

    ASSERT_EQ(expected, day.Stage2(input));
}
