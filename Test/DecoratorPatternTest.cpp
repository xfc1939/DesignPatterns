//
// Created by xfc on 2018/6/18.
//
#include <cstdio>
#include <iostream>
#include "../DecoratorPattern/Decorator.h"


// 装饰模式测试
void DecoratorTest() {
    ConcreteComponent *c = new ConcreteComponent;
    DecoratorA *a = new DecoratorA;
    DecoratorB *b = new DecoratorB;
    std::cout << "test1111" << std::endl;
    a->setComponent(c);
    std::cout << "test1111" << std::endl;
    b->setComponent(a);

    b->operator()();
}


int main(int argc, char* argv[])
{

    DecoratorTest();
    int i;
    std::cin >> i;
    return 0;
}

