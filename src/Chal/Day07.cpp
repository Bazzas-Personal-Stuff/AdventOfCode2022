#include "pch.h"
#include "Day07.h"
#include "gtest/gtest.h"

Day07::FSNode Day07::ParseFSTree(std::istream& input) const {
    using namespace std;
    stringstream outSS;

    FSNode root("/");
    FSNode* currentDir = &root;

    // throw away first line
    string line;
    getline(input, line);
    
    while(getline(input, line)) {
        if(line[0] == '$') {
            if(line[2] == 'c') {
                // cd command
                string targetDir = line.substr(5);
                if(targetDir[0] == '.') {
                    currentDir = currentDir->parent;
                } else {
                    FSNode* newNode = &currentDir->children.emplace_back(targetDir);
                    newNode->parent = currentDir;
                    currentDir = newNode;
                }
            } else {
                // ls command
                continue;
            }
        } else if(line[0] == 'd') {
            // dir response
            // can do nothing, new dirs are handled by cd
        } else {
            // file response
            int fileSize = stoi(line);
            currentDir->AddDirSize(fileSize);
        }
    }

    return root;
}

void Day07::FSNode::AddDirSize(unsigned long childSize) {
    size += childSize;
    if(parent != nullptr) {
        parent->AddDirSize(childSize);
    }
}

unsigned long Day07::FSNode::SumFileLengthsInChildren(unsigned long maxFileSize) const {
    unsigned long childrenSize = 0;
    for(FSNode node : children) {
        childrenSize += node.SumFileLengthsInChildren(maxFileSize);
    }
    if(size <= maxFileSize) {
        return size + childrenSize;
    } 

    return childrenSize;
}

void Day07::FSNode::AddSizeToPQueue(std::priority_queue<unsigned long, std::vector<unsigned long>, std::greater<>>& queue, unsigned long minSize) const {
    if(size >= minSize) {
        queue.push(size);
    }
    for(FSNode node : children) {
        node.AddSizeToPQueue(queue, minSize);
    }
}

std::string Day07::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;
    
    FSNode root = ParseFSTree(input);
    outSS << root.SumFileLengthsInChildren(100000);

    return outSS.str();
}

std::string Day07::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;
    
    FSNode root = ParseFSTree(input);
    priority_queue<unsigned long, vector<unsigned long>, greater<>> fileSizeQueue;
    root.AddSizeToPQueue(fileSizeQueue, 30000000 - (70000000 - root.size));
    outSS << fileSizeQueue.top();

    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day07, Stage1) {
    Day07 day = Day07();

    std::stringstream input = day.GetGivenInput();
    std::string expected("95437");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day07, Stage2) {
    Day07 day = Day07();

    std::stringstream input = day.GetGivenInput();
    std::string expected("24933642");

    ASSERT_EQ(expected, day.Stage2(input));
}
