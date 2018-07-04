//
// Created by xfc on 2018/7/4.
//

#include <cstdio>
#include <iostream>
#include "../SimpleFactory/SimpleFactoryContext.h"


// 工厂模式测试
void SimpleFactoryTest(){
    SimpleFactoryContext context;
    SimpleFactoryBase *base = context.createInstance("A");
    base->getResult();

    SimpleFactoryBase *base1 = context.createInstance("B");
    base1->getResult();

}


int main(int argc, char* argv[])
{
    SimpleFactoryTest();
    int i;
    std::cin >> i;
    return 0;
}

