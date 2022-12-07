#pragma once
#include <queue>

#include "Chal.h"
#include <string>

class Day07 : public Chal {
public:
    class FSNode {
    public:
        void AddDirSize(unsigned long childSize);
        unsigned long SumFileLengthsInChildren(unsigned long maxFileSize) const;
        void AddSizeToPQueue(
            std::priority_queue<unsigned long, std::vector<unsigned long>, std::greater<>>& queue, unsigned long
            minSize) const;
    public:
        FSNode(const std::string& nodeName) : name(nodeName), size(0), parent(nullptr){}
        std::string name;
        unsigned long size;
        std::vector<FSNode> children;
        FSNode* parent;
    };

    FSNode ParseFSTree(std::istream& input) const;

    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;

    virtual std::stringstream GetGivenInput() override {
        return std::stringstream(R"($ cd /
$ ls
dir a
14848514 b.txt
8504156 c.dat
dir d
$ cd a
$ ls
dir e
29116 f
2557 g
62596 h.lst
$ cd e
$ ls
584 i
$ cd ..
$ cd ..
$ cd d
$ ls
4060174 j
8033020 d.log
5626152 d.ext
7214296 k)");
    }

};
