#include "pch.h"
#include "gtest/gtest.h"
#include "Chal/Day01.h"
#include "Chal/Day02.h"

std::filesystem::path inputsDir = "inputs";

std::vector<std::unique_ptr<Chal>> days;
void PopulateDays() {
    days.emplace_back(std::make_unique<Day01>());
    days.emplace_back(std::make_unique<Day02>());
}



int main(int argc, char** argv) {
    PopulateDays(); // Set up strategy
    
    int dayInput;
    int stageInput;
    while(true) {
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
            return RUN_ALL_TESTS();
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