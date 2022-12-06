#include "pch.h"
#include "Day06.h"
#include "gtest/gtest.h"

bool Day06::HasDuplicates(const std::vector<int>& collection) {
    return std::any_of(collection.begin(), collection.end(), [](int count){ return count > 1; });
}

std::string Day06::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;

    int markerIdx = 0;

    deque<char> window;
    vector<int> last4(26, false);
    for(char c; input.get(c); ) {
        last4[c - 'a'] += 1;
        window.push_back(c);
        markerIdx++;
        
        if(markerIdx < 4) {
            continue;
        }
        
        // Window has 3 elements in it
        // Check if the incoming character exists in the window
        if(!HasDuplicates(last4)){
            break;
        }
        // otherwise, pop the front char
        char oldestChar = window.front();
        window.pop_front();
        last4[oldestChar - 'a'] -= 1;
    }  
    
    outSS << markerIdx;
    return outSS.str();
}

std::string Day06::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;

    int markerIdx = 0;

    deque<char> window;
    vector<int> last14(26, false);
    for(char c; input.get(c); ) {
        last14[c - 'a'] += 1;
        window.push_back(c);
        markerIdx++;
        
        if(markerIdx < 14) {
            continue;
        }
        
        // Check if the incoming character exists in the window
        if(!HasDuplicates(last14)){
            break;
        }
        // otherwise, pop the front char
        char oldestChar = window.front();
        window.pop_front();
        last14[oldestChar - 'a'] -= 1;
    }  

    outSS << markerIdx;

    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day06, Stage1) {
    Day06 day = Day06();
    std::stringstream input = day.GetGivenInput();

    std::string expected("7");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day06, Stage2) {
    Day06 day = Day06();
    std::stringstream input = day.GetGivenInput();

    std::string expected("19");

    ASSERT_EQ(expected, day.Stage2(input));
}
