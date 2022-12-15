#pragma once
#include "Chal.h"
#include <string>

class Day13 : public Chal {
public:
    class PacketElement {
    public:
        // virtual bool operator<=(PacketElement& other) = 0;
    };
    
    class PacketInteger : public PacketElement {
    public:
        int value;
    };

    class PacketList : public PacketElement {
    public:
        bool operator<=(PacketList& other) const {
            return false;
        }
        std::vector<std::unique_ptr<PacketElement>> children;
    };
    
    class Packet {
    public:
        bool operator<=(const Packet& other) const {
            return false;
        }
        
        std::unique_ptr<PacketList> root;
    };
    
    
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;

    virtual std::stringstream GetGivenInput() override {
        return std::stringstream(R"([1,1,3,1,1]
[1,1,5,1,1]

[[1],[2,3,4]]
[[1],4]

[9]
[[8,7,6]]

[[4,4],4,4]
[[4,4],4,4,4]

[7,7,7,7]
[7,7,7]

[]
[3]

[[[]]]
[[]]

[1,[2,[3,[4,[5,6,7]]]],8,9]
[1,[2,[3,[4,[5,6,0]]]],8,9])");
    }

    
};
