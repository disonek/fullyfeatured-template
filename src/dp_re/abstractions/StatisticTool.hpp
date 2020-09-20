#pragma once
#include <cstdint>
#include <string>

namespace abstract {

class StatisticTool
{
public:
    StatisticTool();
    ~StatisticTool();
    StatisticTool(const StatisticTool&);
    StatisticTool& operator=(const StatisticTool&);
    StatisticTool(StatisticTool&&);
    StatisticTool& operator=(StatisticTool&&);
    static void printStatistic();
    static void resetStatistic();

    void printIfNotZero(std::string&& desctipton, const uint32_t& counter);

private:
    static uint32_t copyAssignmentOperatorCounter;
    static uint32_t moveAssignmentOperatorCounter;
    static uint32_t copyCtorCounter;
    static uint32_t moveCtorCounter;
    static uint32_t defaultCtorCounter;
    static uint32_t DtorCounter;
};

class ScopedStatisticTool
{
public:
    ScopedStatisticTool(const ScopedStatisticTool&) = delete;
    ScopedStatisticTool& operator=(const ScopedStatisticTool&) = delete;
    ScopedStatisticTool(ScopedStatisticTool&&) = default;
    ScopedStatisticTool& operator=(ScopedStatisticTool&&) = default;
    ScopedStatisticTool()
    {
        StatisticTool::resetStatistic();
    }
    ~ScopedStatisticTool()
    {
        //        StatisticTool::printStatistic();
    }
};
}
