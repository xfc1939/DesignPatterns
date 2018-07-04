//
// Created by xfc on 2018/7/4.
//
#include "../FactoryMethodPattern/FactoryMethodPattern.h"

// 工厂模式测试
void FactoryMethodPatternTest(){
    IFactory *factory = new IFactoryB();
    Operatorion *oper = factory->createOperatorion();
    oper->getResult();
}
int main(int argc, char* argv[])
{

    FactoryMethodPatternTest();
    int i;
    std::cin >> i;
    return 0;
}