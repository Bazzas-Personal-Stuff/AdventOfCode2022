#include "pch.h"
#include "Day14.h"
#include "gtest/gtest.h"

std::pair<int, int> Day14::TransformPoint(std::pair<int, int> point, std::pair<int, int> minPoint) {
    return {point.first - minPoint.first, point.second - minPoint.second};
}

std::vector<std::vector<int>> Day14::GenerateGrid(std::istream& input, std::pair<int, int> startPoint, std::pair<int, int>& outNewStartPoint) const {
    using namespace std;
    vector<pair<pair<int, int>, pair<int, int>>> lineDefinitions;
    pair<int, int> minCoords(startPoint);
    pair<int, int> maxCoords(startPoint);

    string line;
    while(getline(input, line)) {
        stringstream lineSS(line);
        string temp;
        char tempChar;
        
        bool isFirstPoint = true;
        pair<int, int> thisPoint;
        pair<int, int> lastPoint;
        do {
            lineSS >> thisPoint.first >> tempChar >> thisPoint.second;
            // Update grid extents
            if(thisPoint.first > maxCoords.first) {
                maxCoords.first = thisPoint.first;
            }
            if(thisPoint.second > maxCoords.second) {
                maxCoords.second = thisPoint.second;
            }
            if(thisPoint.first < minCoords.first) {
                minCoords.first = thisPoint.first;
            }
            if(thisPoint.second < minCoords.second) {
                minCoords.second = thisPoint.second;
            }
            
            if(!isFirstPoint) {
                lineDefinitions.emplace_back(lastPoint, thisPoint);
            }
            isFirstPoint = false;
            lastPoint = thisPoint;
        } while (lineSS >> temp);
    }

    maxCoords.second += 2;
    
    minCoords.first = startPoint.first - maxCoords.second;
    maxCoords.first = startPoint.first + maxCoords.second;
    lineDefinitions.push_back({{minCoords.first, maxCoords.second}, {maxCoords.first, maxCoords.second}});

    int sizeX = maxCoords.first - minCoords.first + 1;
    int sizeY = maxCoords.second - minCoords.second + 1;

    // Set up grid /////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Column-major, [x][y]
    vector<vector<int>> grid(sizeX, vector<int>(sizeY, 0));

    // Transform start point into new coords
    outNewStartPoint.first = startPoint.first - minCoords.first;
    outNewStartPoint.second = startPoint.second - minCoords.second;
    
    for(auto pointPair : lineDefinitions) {
        // subtract minCoords from point
        pair<int, int> beginPoint = TransformPoint(pointPair.first, minCoords);
        pair<int, int> endPoint = TransformPoint(pointPair.second, minCoords);
        pair<int, int> currentPoint(beginPoint);

        while(currentPoint != endPoint) {
            grid[currentPoint.first][currentPoint.second] = 1;
            
            if(currentPoint.first < endPoint.first) {
                currentPoint.first += 1;
            }
            if(currentPoint.first > endPoint.first) {
                currentPoint.first -= 1;
            }
            if(currentPoint.second < endPoint.second) {
                currentPoint.second += 1;
            }
            if(currentPoint.second > endPoint.second) {
                currentPoint.second -= 1;
            }
        }
        grid[endPoint.first][endPoint.second] = 1;
    }

    grid[outNewStartPoint.first][outNewStartPoint.second] = 3; // Set starting point
    return grid;
}

int Day14::FillGridWithSand(std::vector<std::vector<int>>& grid, std::pair<int, int> startPoint, std::function<bool(std::pair<int, int>)> ShouldExit) {
    using namespace std;
    int sandCount = 0;
    while(true) {
        pair<int, int> sandPos(startPoint);

        while(true) {
            
            // Check for air below
            if(grid[sandPos.first][sandPos.second + 1] == 0) {
                // move down one
                sandPos.second += 1;
            }
            // Check for air down and left
            else if(grid[sandPos.first - 1][sandPos.second + 1] == 0) {
                sandPos.first -= 1;
                sandPos.second += 1;
            }
            // Check for air down and right;
            else if(grid[sandPos.first + 1][sandPos.second + 1] == 0) {
                sandPos.first += 1;
                sandPos.second += 1;
            }
            // Floor is stable, sand comes to rest
            else {
                grid[sandPos.first][sandPos.second] = 2; // Set grid value to "Sand"
                break;
            }
                
        }

        if(ShouldExit(sandPos)){
            return sandCount;
        }

        sandCount += 1;
    }

    return sandCount;
}

void Day14::PrintGrid(std::vector<std::vector<int>>& grid) {
    using namespace std;
    for(int y = 0; y < grid[0].size(); y++) {
        for(int x = 0; x < grid.size(); x++) {
            int cellVal = grid[x][y];
            if(cellVal == 0) cout << '.'; // air
            else if(cellVal == 1) cout << '#'; // wall
            else if(cellVal == 2) cout << 'o'; // sand
            else cout << '+'; // start point
        }
        cout << endl;
    }
}


std::string Day14::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    pair<int, int> startPoint;
    vector<vector<int>> grid = GenerateGrid(input, {500, 0}, startPoint);
    int sandCount = FillGridWithSand(grid, startPoint, [grid](pair<int, int> sandPos) {
        // Stops as soon as sand hits the floor
        return sandPos.first == 0 || sandPos.first == grid.size() - 1 || sandPos.second == grid[0].size() - 2;
    });
    PrintGrid(grid);
    
    outSS << sandCount;

    return outSS.str();
}

std::string Day14::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;

    pair<int, int> startPoint;
    vector<vector<int>> grid = GenerateGrid(input, {500, 0}, startPoint);
    int sandCount = FillGridWithSand(grid, startPoint, [startPoint](pair<int, int> sandPos) {
        // Stops when sand blocks the start point
        return sandPos == startPoint;
    });
    PrintGrid(grid);
    
    outSS << sandCount + 1;

    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day14, Stage1) {
    Day14 day = Day14();

    std::stringstream input = day.GetGivenInput();
    std::string expected("24");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day14, Stage2) {
    Day14 day = Day14();

    std::stringstream input = day.GetGivenInput();
    std::string expected("93");

    ASSERT_EQ(expected, day.Stage2(input));
}
