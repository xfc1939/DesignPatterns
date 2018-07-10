//
// Created by xfc on 2018/7/10.
//
#include "../ObserverPattern/ObserverPattern.h"

int main() {
    Subject *sub = new ConcreteSubject("123");
    sub->add(new ConcreteObserver("A"));
    sub->add(new ConcreteObserver("B"));
    sub->add(new ConcreteObserver("C"));
    sub->notify();
    return 0;
}
