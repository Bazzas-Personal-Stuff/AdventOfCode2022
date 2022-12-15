#pragma once
#include "Chal.h"
#include <string>

class Day14 : public Chal {
public:
    static std::pair<int, int> TransformPoint(std::pair<int, int> point, std::pair<int, int> minPoint);
    std::vector<std::vector<int>> GenerateGrid(std::istream& input, std::pair<int, int> startPoint, std::pair<int, int>& outNewStartPoint) const;
    static int FillGridWithSand(std::vector<std::vector<int>>& grid, std::pair<int, int> startPoint, std::function<bool(std::pair<int, int>)>
                                ShouldExit);
    static void PrintGrid(std::vector<std::vector<int>>& grid);
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;

    virtual std::stringstream GetGivenInput() override {
        return std::stringstream(R"(498,4 -> 498,6 -> 496,6
503,4 -> 502,4 -> 502,9 -> 494,9)");
    }

    
};
