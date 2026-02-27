#pragma once
#include <thread>
#include <chrono>
#include <random>
using namespace std::chrono_literals;

struct ITask {
public:
    virtual ~ITask() = default;
    virtual void Execute() = 0;
    virtual unsigned GetDifficulty() const noexcept = 0;
};

struct SimpleTask final : ITask{
public:
    void Execute() override {
        std::this_thread::sleep_for(100ms);
    }

    unsigned GetDifficulty() const noexcept override {
        return 100U;
    }
};

struct DifficultTask : ITask {
public:
    DifficultTask(unsigned difficulty = 10U) : difficulty(difficulty) {}

    void Execute() override {
        std::this_thread::sleep_for(difficulty * 1ms );
    }

    unsigned GetDifficulty() const noexcept override {
        return difficulty;
    }

protected:
    unsigned difficulty;
};

struct RandDifficultTask final : DifficultTask{
public:
    RandDifficultTask() : DifficultTask(dist(gen)) {}

protected:
    static inline std::mt19937 gen {0U};
    static inline std::uniform_int_distribution<unsigned> dist{1, 100};
};