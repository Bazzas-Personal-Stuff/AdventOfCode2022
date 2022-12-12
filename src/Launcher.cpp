#include "pch.h"
#include "gtest/gtest.h"
#include "Chal/Day01.h"
#include "Chal/Day02.h"
#include "Chal/Day03.h"
#include "Chal/Day04.h"
#include "Chal/Day05.h"
#include "Chal/Day06.h"
#include "Chal/Day07.h"
#include "Chal/Day08.h"
#include "Chal/Day09.h"
#include "Chal/Day10.h"
#include "Chal/Day11.h"
#include "Chal/Day12.h"

const std::filesystem::path inputsDir = "inputs";
constexpr int YEAR = 2022;
constexpr bool AUTO_DOWNLOAD_INPUTS = true; // TODO: make a preprocessor define or something

std::vector<std::unique_ptr<Chal>> days;
void PopulateDays() {
    days.emplace_back(std::make_unique<Day01>());
    days.emplace_back(std::make_unique<Day02>());
    days.emplace_back(std::make_unique<Day03>());
    days.emplace_back(std::make_unique<Day04>());
    days.emplace_back(std::make_unique<Day05>());
    days.emplace_back(std::make_unique<Day06>());
    days.emplace_back(std::make_unique<Day07>());
    days.emplace_back(std::make_unique<Day08>());
    days.emplace_back(std::make_unique<Day09>());
    days.emplace_back(std::make_unique<Day10>());
    days.emplace_back(std::make_unique<Day11>());
    days.emplace_back(std::make_unique<Day12>());
}


int main(int argc, char** argv) {
    PopulateDays(); // Set up strategy
    
    int dayInput;
    int stageInput;

    while(true) {
        while(true) {
            std::cout << "===========================" << std::endl;
            std::cout << "Day [1-"<< days.size() <<"]: ";
            std::cin >> dayInput;


            // if not in range of available day solutions
            if(!(dayInput > 0 && dayInput <= (int)days.size())) {
                continue;
            }

            std::cout << "Stage [1 or 2, 0 to test]: ";
            std::cin >> stageInput;

            if(stageInput == 0) {
                testing::InitGoogleTest(&argc, argv);
                ::testing::GTEST_FLAG(filter) = std::format("Day{:02d}*", dayInput);
                RUN_ALL_TESTS();
                continue;
            }
            // if stage isn't 1 or 2
            if(!(stageInput == 1 || stageInput == 2)) {
                continue;
            }

            break;
        }

        std::cout << "\n===== Day " << dayInput << ", Stage " << stageInput <<" =====" << std::endl;

        // input file to string
        std::string fileName = std::format("input{:02d}.txt", dayInput);
        std::filesystem::path p = std::filesystem::current_path();
        p /= inputsDir / fileName;
        
        // Automatically download input if we don't have it already. Requires "aocd" to be set up with a session token.
        if(!exists(p)) {
            if(!AUTO_DOWNLOAD_INPUTS) {
                std::cout << "Input is missing and AUTO_DOWNLOAD_INPUTS is not enabled." << std::endl;
                continue;
            }
            
            // std::cout << absolute(p) << std::endl;
            system(std::format("aocd {0} > \"{1}\" {2}", dayInput, absolute(p).string(), YEAR).c_str());
        }
        std::ifstream input(p);

        // Run the requested stage
        dayInput -= 1; // 1-index to 0-index
        if(stageInput == 1) {
            std::cout << days[dayInput]->Stage1(input) << std::endl;
        }
        else {
            std::cout << days[dayInput]->Stage2(input) << std::endl;
        }
        input.close();

    }
}