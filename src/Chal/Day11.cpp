#include "pch.h"
#include "Day11.h"
#include "gtest/gtest.h"

Day11::Operation::Operation(const std::string& lhs, const std::string& rhs, const char op) {
    if(lhs == "old") {
        m_LhsOperand = std::make_unique<IdentifierOperand>();
    }
    else {
        m_LhsOperand = std::make_unique<ConstOperand>(std::stoi(lhs));
    }
    
    if(rhs == "old") {
        m_RhsOperand = std::make_unique<IdentifierOperand>();
    }
    else {
        m_RhsOperand = std::make_unique<ConstOperand>(std::stoi(rhs));
    }

    switch (op) {
    case '+':
        m_Op = Add;
        break;
    case '-':
        m_Op = Sub;
        break;
    case '*':
        m_Op = Mul;
        break;
    case '/':
        m_Op = Div;
        break;
    default:
        m_Op = Add;
        break;
    }
}

long Day11::Operation::Eval(long oldVal) const {
    long lhs = m_LhsOperand->Eval(oldVal);
    long rhs = m_RhsOperand->Eval(oldVal);

    switch(m_Op) {
    case Add: return lhs + rhs;
    case Sub: return lhs - rhs;
    case Mul: return lhs * rhs;
    case Div: return lhs / rhs;
    default: return -9999999;
    }
}

std::vector<Day11::Monkey> Day11::ParseMonkeys(std::istream& input) {
    using namespace std;
    vector<Monkey> monkeys;

    string garbage;
    while(input >> garbage >> garbage >> garbage >> garbage) {
        Monkey& monkey = monkeys.emplace_back();

        // Starting items
        string startingItemsStr;
        getline(input, startingItemsStr);
        stringstream startingItemsSS(startingItemsStr);
        string item;
        while(getline(startingItemsSS, item, ',')) {
            monkey.items.push_back(stoi(item));
        }
        
        // Operation
        char op;
        string lhs, rhs;
        input >> garbage >> garbage >> garbage >> lhs >> op >> rhs;
        monkey.operation = make_unique<Operation>(lhs, rhs, op);

        // Get test value
        input >> garbage >> garbage >> garbage >> monkey.testVal;

        // Get targets
        input >> garbage >> garbage >> garbage >> garbage >> garbage >> monkey.trueTarget;
        input >> garbage >> garbage >> garbage >> garbage >> garbage >> monkey.falseTarget;
    }

    return monkeys;
}

void Day11::EvalMonkeys(std::vector<Day11::Monkey>& monkeys, int iterCount, int divide, long testProduct) {
    for(int round = 0; round < iterCount; round++) {
        for(int monkeyIdx = 0; monkeyIdx < monkeys.size(); monkeyIdx++) {
            Monkey& monkey = monkeys[monkeyIdx];
            
            // iterate items backwards so we can pop
            for(int i = monkey.items.size() - 1; i >= 0; i--) {
                monkey.inspectCount++;
                // Inspect item
                long worryLevel = monkey.items[i];
                monkey.items[i] = (monkey.operation->Eval(worryLevel) / divide) % testProduct;
                // if(monkey.items[i] > testProduct || monkey.items[i] < 0) {
                //     int item = monkey.items[i];
                //     std::cout << item << std::endl;
                // }
                // Test
                if(monkey.items[i] % monkey.testVal == 0) {
                    monkeys[monkey.trueTarget].items.push_back(monkey.items[i]);
                }
                else {
                    monkeys[monkey.falseTarget].items.push_back(monkey.items[i]);
                }
                monkey.items.pop_back();
            }
        }
    }
}

std::string Day11::Stage1(std::istream& input) {
    using namespace std;
    stringstream outSS;
    
    vector<Monkey> monkeys = ParseMonkeys(input);
    long testProduct = 1;
    for(Monkey& monkey : monkeys) {
        testProduct *= monkey.testVal;
    }
    EvalMonkeys(monkeys, 20, 3, testProduct);

    // Output answer
    sort(monkeys.begin(), monkeys.end(), [](Monkey& a, Monkey& b){ return a.inspectCount > b.inspectCount;});
    outSS << monkeys[0].inspectCount * monkeys[1].inspectCount;
    return outSS.str();
}

std::string Day11::Stage2(std::istream& input) {
    using namespace std;
    stringstream outSS;
    
    vector<Monkey> monkeys = ParseMonkeys(input);
    long testProduct = 1;
    for(Monkey& monkey : monkeys) {
        testProduct *= monkey.testVal;
    }
    EvalMonkeys(monkeys, 10000, 1, testProduct);

    // Output answer
    sort(monkeys.begin(), monkeys.end(), [](Monkey& a, Monkey& b){ return a.inspectCount > b.inspectCount;});
    outSS << monkeys[0].inspectCount * monkeys[1].inspectCount;
    return outSS.str();
}


// =============== gtests for given cases ===============

TEST(Day11, Stage1) {
    Day11 day = Day11();

    std::stringstream input = day.GetGivenInput();
    std::string expected("10605");

    ASSERT_EQ(expected, day.Stage1(input));
}

TEST(Day11, Stage2) {
    Day11 day = Day11();

    std::stringstream input = day.GetGivenInput();
    std::string expected("2713310158");

    ASSERT_EQ(expected, day.Stage2(input));
}
