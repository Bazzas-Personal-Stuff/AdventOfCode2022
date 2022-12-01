﻿#include "pch.h"
#include "gtest/gtest.h"
#include "Chal/Day01.h"

std::filesystem::path inputsDir = "inputs";

std::vector<std::unique_ptr<Chal>> days;
void PopulateDays() {
    days.emplace_back(std::make_unique<Day01>());
}



int main(int argc, char** argv) {
    PopulateDays(); // Set up strategy
    
    int dayInput;
    int stageInput;
    while(true) {
        std::cout << "Day [1-"<< days.size() <<", or 0 to test]: ";
        std::cin >> dayInput;

        if(dayInput == 0) {
            testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        }

        // if not in range of available day solutions
        if(!(dayInput > 0 && dayInput <= (int)days.size())) {
            continue;
        }

        std::cout << "Stage [1 or 2]: ";
        std::cin >> stageInput;

        // if stage isn't 1 or 2
        if(!(stageInput == 1 || stageInput == 2)) {
            continue;
        }

        break;
    }

    std::cout << "\n===== Day " << dayInput << ", Stage " << stageInput <<" =====" << std::endl;

    // input file to string
    std::string fileName = std::format("input{:02d}.txt", dayInput);
    inputsDir /= fileName;
    std::filesystem::path p = std::filesystem::current_path();
    p /= inputsDir;

    std::ifstream t(p);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string input = buffer.str();

    // Run the requested stage
    dayInput -= 1; // 1-index to 0-index
    if(stageInput == 1) {
        std::cout << days[dayInput]->Stage1(input) << std::endl;
    }
    else {
        std::cout << days[dayInput]->Stage2(input) << std::endl;
    }

}