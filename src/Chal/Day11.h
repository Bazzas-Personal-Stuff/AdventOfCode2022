#pragma once
#include "Chal.h"
#include <string>

class Day11 : public Chal {
public:
    enum Operator {
        Add,
        Sub,
        Mul,
        Div,
    };
    
    class Operand {
    public:
        virtual ~Operand() = default;
        virtual long Eval(const long oldVal) const = 0;
    };

    class ConstOperand : public Operand {
    public:
        ConstOperand(long val) : m_Val(val) {}
        virtual long Eval(const long oldVal) const override { return m_Val; }
    private:
        long m_Val;
    };

    class IdentifierOperand : public Operand {
    public:
        IdentifierOperand() = default;
        virtual long Eval(const long oldVal) const override { return oldVal; }
    };
    
    class Operation {
    public:
        Operation(const std::string& lhs, const std::string& rhs, const char op);
        long Eval(long oldVal) const;
        
    private:
        std::unique_ptr<Operand> m_LhsOperand;
        std::unique_ptr<Operand> m_RhsOperand;
        Operator m_Op;
    };
    
    class Monkey {
    public:
        Monkey() = default;
        
        std::vector<long> items = std::vector<long>();

        std::unique_ptr<Operation> operation = nullptr;
        long testVal = 0;
        int trueTarget = 0;
        int falseTarget = 0;

        long inspectCount = 0;
    };

    static std::vector<Day11::Monkey> ParseMonkeys(std::istream& input);
    static void EvalMonkeys(std::vector<Monkey>& monkeys, int iterCount, int divide, long testProduct);
    virtual std::string Stage1(std::istream& input) override;
    virtual std::string Stage2(std::istream& input) override;

    virtual std::stringstream GetGivenInput() override {
        return std::stringstream(R"(Monkey 0:
  Starting items: 79, 98
  Operation: new = old * 19
  Test: divisible by 23
    If true: throw to monkey 2
    If false: throw to monkey 3

Monkey 1:
  Starting items: 54, 65, 75, 74
  Operation: new = old + 6
  Test: divisible by 19
    If true: throw to monkey 2
    If false: throw to monkey 0

Monkey 2:
  Starting items: 79, 60, 97
  Operation: new = old * old
  Test: divisible by 13
    If true: throw to monkey 1
    If false: throw to monkey 3

Monkey 3:
  Starting items: 74
  Operation: new = old + 3
  Test: divisible by 17
    If true: throw to monkey 0
    If false: throw to monkey 1)");
    }

    
};
