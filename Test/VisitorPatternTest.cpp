//
// Created by xfc on 2018/8/22.
//

#include <iostream>
#include "../VisitorPattern/VisitorPattern.h"
void test() {
    Visitor *visitor = new ConcreteVistorA();
    ConcreteElementA concreteElementA;
    ConcreteElementB concreteElementB;
    concreteElementA.accept(visitor);
    concreteElementB.accept(visitor);
}

int main() {
    test();
    return 0;
}