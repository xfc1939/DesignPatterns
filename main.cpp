//
// Created by xfc on 2018/6/18.
//
#include <cstdio>
#include <iostream>
#include "SimpleFactory/SimpleFactoryContext.h"
#include "StrategyPattern/StrategyContext.h"
#include "DecoratorPattern/Decorator.h"
#include "ProxyPattern/Proxy.h"
#include "FactoryMethodPattern/FactoryMethodPattern.h"

// 工厂模式测试
void SimpleFactoryTest(){
    SimpleFactoryContext context;
    SimpleFactoryBase *base = context.createInstance("A");
    base->getResult();

    SimpleFactoryBase *base1 = context.createInstance("B");
    base1->getResult();

}

// 策略模式测试
void StrategyTest(){

    StrategyContext context1;
    context1.createInstance("A");
    context1.getResult();

}

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

// 代理模式测试
void ProxyTest() {
    RealSubject *subject = new RealSubject;
    Proxy *proxy = new Proxy;
    proxy->setSubject(subject);
    proxy->request();
}

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

