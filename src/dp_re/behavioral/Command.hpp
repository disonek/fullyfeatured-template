#pragma once

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory>
#include <stack>
#include "Product.hpp"

namespace behav {
class Command
{
public:
    virtual ~Command() = default;
    Command(Command&&) = default;
    Command& operator=(Command&&) = default;
    Command() = default;
    Command(const Command&) = default;
    Command& operator=(const Command&) = default;

    virtual void execute() = 0;
    virtual void undo() = 0;
};

class ReciverLeague
{
public:
    ReciverLeague(std::string name)
        : health{100}
        , name{name}
    {
    }

    void printHealt()
    {
        std::cout << name << ": My health is= " << health << std::endl;
    }

    std::uint32_t health;
    std::string name;
};

class CommandADAtack : public Command
{
public:
    CommandADAtack(std::shared_ptr<ReciverLeague> reciver)
        : reciver{reciver}
    {
    }

    virtual void execute() override
    {
        reciver->health = reciver->health - 10;
    }

    virtual void undo() override
    {
        reciver->health = reciver->health + 10;
    }

private:
    std::shared_ptr<ReciverLeague> reciver;
};

class CommandAPAtack : public Command
{
public:
    CommandAPAtack(std::shared_ptr<ReciverLeague> reciver)
        : reciver{reciver}
    {
    }

    virtual void execute() override
    {
        reciver->health = reciver->health - 20;
    }

    virtual void undo() override
    {
        reciver->health = reciver->health + 20;
    }

private:
    std::shared_ptr<ReciverLeague> reciver;
};

class InvokerDamager
{
public:
    void addCommand(std::unique_ptr<Command>&& command)
    {
        doCommands.emplace(std::move(command));
    }

    void runCommands()
    {
        while(!doCommands.empty())
        {
            doCommands.top()->execute();
            undoCommands.emplace(std::move(doCommands.top()));
            doCommands.pop();
        }
    }

    void restoreCommands()
    {
        while(!undoCommands.empty())
        {
            undoCommands.top()->undo();
            undoCommands.pop();
        }
    }

    std::stack<std::unique_ptr<Command>> doCommands;
    std::stack<std::unique_ptr<Command>> undoCommands;
};
}
