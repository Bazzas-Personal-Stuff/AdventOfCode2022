#pragma once
#include <queue>

#include "Chal.h"
#include <string>

#include "UtilHash.h"

class Day12 : public Chal {
public:
    struct Coords {
        std::pair<int, int> pos;
        int weight = 0;
        
    };

    class Priority {
    public:
        bool operator()(const Coords& a, const Coords& b) const;
    };

    
    int GetPriority(std::pair<int, int> fromPoint, std::pair<int, int> toPoint, std::function<int(std::pair<int, int>, std::pair<int, int>)
                    > Heuristic);
    static int Manhattan(std::pair<int, int> fromPoint, std::pair<int, int> toPoint);
    void CheckPosition(
        std::pair<int, int> checkPos, std::pair<int, int> currentPos, std::function<int(std::pair<int, int>, std::pair<int,
            int>)> Heuristic);
    bool IsValidMove(std::pair<int, int> fromPoint, std::pair<int, int> toPoint);
    int Pathfind(
        std::istream& input, std::function<bool(std::pair<int, int>, std::pair<int, int>)> TargetCheck, std::function<int(
            std::pair<int, int>, std::pair<int, int>)> Heuristic);
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;

    virtual std::stringstream GetGivenInput() override {
        return std::stringstream(R"(Sabqponm
abcryxxl
accszExk
acctuvwj
abdefghi)");
    }

    std::vector<std::vector<char>> HeightMap;
    std::priority_queue<Coords, std::vector<Coords>, Priority> Frontier; 
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, pair_hash> PathParents;
    std::pair<int, int> StartPos {};
    std::pair<int, int> EndPos {};
    std::unordered_map<std::pair<int, int>, int, pair_hash> PathCosts {};
};
