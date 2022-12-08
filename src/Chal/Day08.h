#pragma once
#include <vector>

#include "Chal.h"
#include <string>

class Day08 : public Chal {
public:
    std::vector<std::vector<int>> GenerateGrid(std::istream& input) const;
    static bool CheckCellVisibility(int row, int col, const std::vector<std::vector<int>>& grid);
    static int GetScenicScore(int row, int col, const std::vector<std::vector<int>>& grid);
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;

    virtual std::stringstream GetGivenInput() override {
        return std::stringstream(R"(30373
25512
65332
33549
35390)");
    }

    
};
