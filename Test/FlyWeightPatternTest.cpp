//
// Created by xfc on 2018/8/21.
//
#include "../FlyWeightPattern/FlyWeightPattern.h"

void Test()
{
    int i = 20;
    FlyweightFactory factory;
    Flyweight* fly = factory.getFlyweight("X");
    fly->operation(i);
}
int main()
{
    Test();
    return 0;
}
