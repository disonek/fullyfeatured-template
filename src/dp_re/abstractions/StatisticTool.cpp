#include "StatisticTool.hpp"
#include <iostream>

namespace abstract {
uint32_t StatisticTool::copyAssignmentOperatorCounter = 0;
uint32_t StatisticTool::moveAssignmentOperatorCounter = 0;
uint32_t StatisticTool::copyCtorCounter = 0;
uint32_t StatisticTool::moveCtorCounter = 0;
uint32_t StatisticTool::defaultCtorCounter = 0;
uint32_t StatisticTool::DtorCounter = 0;

StatisticTool::StatisticTool()
{
    defaultCtorCounter++;
}

StatisticTool::~StatisticTool()
{
    DtorCounter++;
}

StatisticTool::StatisticTool(const StatisticTool&)
{
    copyCtorCounter++;
}

StatisticTool& StatisticTool::operator=(const StatisticTool&)
{
    copyAssignmentOperatorCounter++;
    return *this;
}

StatisticTool::StatisticTool(StatisticTool&&)
{
    moveCtorCounter++;
}

StatisticTool& StatisticTool::operator=(StatisticTool&&)
{
    moveAssignmentOperatorCounter++;
    return *this;
}

void StatisticTool::printStatistic()
{
    StatisticTool st;
    std::cout << "[StatisticTool]" << std::endl;
    st.printIfNotZero("default Ctor counter = ", defaultCtorCounter);
    st.printIfNotZero("destructor counter = ", DtorCounter);
    st.printIfNotZero("copy Ctor counter = ", copyCtorCounter);
    st.printIfNotZero("copy assignment operator counter = ", copyAssignmentOperatorCounter);
    st.printIfNotZero("move Ctor counter = ", moveCtorCounter);
    st.printIfNotZero("move assignment operator counter = ", moveAssignmentOperatorCounter);
}

void StatisticTool::resetStatistic()
{
    copyAssignmentOperatorCounter = 0;
    moveAssignmentOperatorCounter = 0;
    copyCtorCounter = 0;
    moveCtorCounter = 0;
    defaultCtorCounter = 0;
    DtorCounter = 0;
}

void StatisticTool::printIfNotZero(std::string&& desctipton, const uint32_t& counter)
{
    if(counter != 0)
        std::cout << desctipton << counter << std::endl;
}
}
