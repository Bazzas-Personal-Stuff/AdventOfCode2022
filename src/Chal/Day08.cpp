#include "pch.h"
#include "Day08.h"
#include "gtest/gtest.h"

// Row-major grid
std::vector<std::vector<int>> Day08::GenerateGrid(std::istream& input) const {
    using namespace std;
    vector<vector<int>> grid;

    for(string inStr; getline(input, inStr);) {
        vector<int>& row = grid.emplace_back();
        for(char c : inStr) {
            int val = c - '0';
            row.push_back(val);
        }
    }

    return grid;
}

bool Day08::CheckCellVisibility(int row, int col, const std::vector<std::vector<int>>& grid) {
    using namespace std;
    if(row == 0 || row == grid.size() - 1 ||
        col == 0 || col == grid[0].size() - 1) {
        return true;
    }

    int thisVal = grid[row][col];

    // Check north
    for(int checkRow = row - 1; checkRow >= -1; checkRow--) {
        if(checkRow == -1) return true;
        if(grid[checkRow][col] >= thisVal) break;
    }
    // Check south
    for(int checkRow = row + 1; checkRow <= grid[0].size(); checkRow++) {
        if(checkRow == grid.size()) return true;
        if(grid[checkRow][col] >= thisVal) break;
    }
    // Check east
    for(int checkCol = col + 1; checkCol <= grid[0].size(); checkCol++) {
        if(checkCol == grid[0].size()) return true;
        if(grid[row][checkCol] >= thisVal) break;
    }
    // Check west
    for(int checkCol = col - 1; checkCol >= -1; checkCol--) {
        if(checkCol == -1) return true;
        if(grid[row][checkCol] >= thisVal) break;
    }

    return false;
}

int Day08::GetScenicScore(int row, int col, const std::vector<std::vector<int>>& grid) {
    if(row == 0 || row == grid.size() - 1 ||
        col == 0 || col == grid[0].size() - 1) {
        return 0;
    }

    int thisVal = grid[row][col];
    
    // Check north
    int northScore = 1;
    for(int checkRow = row - 1; checkRow > 0; checkRow--) {
        if(checkRow <= 0) break;
        if(grid[checkRow][col] >= thisVal) break;

        northScore++;
    }
    // Check south
    int southScore = 1;
    for(int checkRow = row + 1; checkRow < grid[0].size(); checkRow++) {
        if(checkRow == grid.size() - 1) break;
        if(grid[checkRow][col] >= thisVal) break;

        southScore++;
    }
    // Check east
    int eastScore = 1;
    for(int checkCol = col + 1; checkCol < grid[0].size(); checkCol++) {
        if(checkCol == grid[0].size() - 1) break;
        if(grid[row][checkCol] >= thisVal) break;

        eastScore++;
    }
    // Check west
    int westScore = 1;
    for(int checkCol = col - 1; checkCol >= 0; checkCol--) {
        if(checkCol <= 0) break;
        if(grid[row][checkCol] >= thisVal) break;

        westScore++;
    }

    return northScore * southScore * eastScore * westScore;
}


std::string Day08::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    auto grid = GenerateGrid(input);
    int countVisible = 0;
    for(int row = 0; row < grid.size(); row++) {
        for(int col = 0; col < grid[0].size(); col++) {
            if(CheckCellVisibility(row, col, grid)) {
                countVisible++;
            }
        }
    }

    outSS << countVisible;
    return outSS.str();
}

std::string Day08::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;

    auto grid = GenerateGrid(input);
    int bestScore = 0;
    
    for(int row = 0; row < grid.size(); row++) {
        for(int col = 0; col < grid[0].size(); col++) {
            int thisScore = GetScenicScore(row, col, grid);
            if(thisScore > bestScore) {
                bestScore = thisScore;
            }
        }
    }

    outSS << bestScore;
    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day08, Stage1) {
    Day08 day = Day08();

    std::stringstream input = day.GetGivenInput();
    std::string expected("21");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day08, Stage2) {
    Day08 day = Day08();

    std::stringstream input = day.GetGivenInput();
    std::string expected("8");

    ASSERT_EQ(expected, day.Stage2(input));
}
