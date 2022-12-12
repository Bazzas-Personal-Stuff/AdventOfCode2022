#pragma once

struct pair_hash {
    size_t operator() (const std::pair<int, int>& p) const {
        return std::rotl(std::hash<int>{}(p.first),1) ^
               std::hash<int>{}(p.second);
    }
};
