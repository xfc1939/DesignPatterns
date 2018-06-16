//
// Created by xfc on 2018/6/15.
//

#ifndef DESIGNPATTERNS_STRATEGYBASE_H
#define DESIGNPATTERNS_STRATEGYBASE_H

class StrategyBase {
public:
    StrategyBase() = default;
    ~StrategyBase() = default;

public:
    virtual int getResult() {
        return 0;
    }
};

#endif //DESIGNPATTERNS_STRATEGYBASE_H
