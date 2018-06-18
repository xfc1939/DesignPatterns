//
// Created by xfc on 2018/6/15.
//
#include "../SimpleFactory/SimpleFactoryContext.h"

#ifndef DESIGNPATTERNS_STRATEGYCONTEXT_H
#define DESIGNPATTERNS_STRATEGYCONTEXT_H


class StrategyContext {

public:
    StrategyContext():m_base(nullptr) {};
    ~StrategyContext() = default;

public:
    void createInstance(const std::string &str);
    void getResult();

private:
    SimpleFactoryBase *m_base;
};


#endif //DESIGNPATTERNS_STRATEGYCONTEXT_H
