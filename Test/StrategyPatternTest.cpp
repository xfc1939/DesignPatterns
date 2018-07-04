//
// Created by xfc on 2018/7/4.
//

#include <cstdio>
#include <iostream>
#include "../StrategyPattern/StrategyContext.h"

// 策略模式测试
void StrategyTest(){

    StrategyContext context1;
    context1.createInstance("A");
    context1.getResult();

}

int main(int argc, char* argv[])
{

    StrategyTest();
    int i;
    std::cin >> i;
    return 0;
}

