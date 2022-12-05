#include "pch.h"
#include "Day05.h"
#include "gtest/gtest.h"

std::vector<std::deque<char>> Day05::ParseCargo(std::istream& input) {
    using namespace std;
    // Get number of columns
    string tempStr;
    getline(input, tempStr);
    input.seekg(0, ios::beg);
    size_t columnCount = (tempStr.size() + 1) / 4;

    auto columns = vector<deque<char>>(columnCount + 1); // index 0 is unused
    
    // Parse cargo drawing
    for(std::string rowStr; getline(input, rowStr);) {
        if(rowStr[1] == '1') {
            // Bottom of the cargo drawing
            break;
        }

        for(int i = 0; i < columns.size() - 1; i++) {
            // Offset is 1, stride is 4
            char boxVal = rowStr[1 + (i * 4)];
            if(boxVal != ' ') {
                columns[i + 1].push_front(boxVal);
            }
        }
    }

    return columns;
}

std::string Day05::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    auto columns = ParseCargo(input);
    
    // Instructions
    string discard;
    int n, source, dest;
    while(input >> discard >> n >> discard >> source >> discard >> dest) {
        for(int i = 0; i < n; i++) {
            char box = columns[source].back();
            columns[source].pop_back();
            columns[dest].push_back(box);
        }
    }

    // Print result
    for(int i = 1; i < columns.size(); i++) {
        outSS << columns[i].back();
    }

    return outSS.str();
}

std::string Day05::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;

    auto columns = ParseCargo(input);

    // Instructions
    string discard;
    int n, source, dest;
    while(input >> discard >> n >> discard >> source >> discard >> dest) {
        stack<char> tempStack = stack<char>(); // Intermediate stack for moving multiple boxes at once
        for(int i = 0; i < n; i++) {
            char box = columns[source].back();
            columns[source].pop_back();
            tempStack.push(box);
        }
        for(int i = 0; i < n; i++) {
            columns[dest].push_back(tempStack.top());
            tempStack.pop();
        }
    }

    // Print result
    for(int i = 1; i < columns.size(); i++) {
        outSS << columns[i].back();
    }

    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day05, Stage1) {
    Day05 day = Day05();
    std::string input(R"(    [D]    
[N] [C]    
[Z] [M] [P]
 1   2   3 

move 1 from 2 to 1
move 3 from 1 to 3
move 2 from 2 to 1
move 1 from 1 to 2)");

    std::stringstream inputSS(input);
    std::string expected("CMZ");

    ASSERT_EQ(expected, day.Stage1(inputSS));
}

TEST(Day05, Stage2) {
    Day05 day = Day05();
    std::string input(R"(    [D]    
[N] [C]    
[Z] [M] [P]
 1   2   3 

move 1 from 2 to 1
move 3 from 1 to 3
move 2 from 2 to 1
move 1 from 1 to 2)");
    
    std::stringstream inputSS(input);
    std::string expected("MCD");

    ASSERT_EQ(expected, day.Stage2(inputSS));
}
