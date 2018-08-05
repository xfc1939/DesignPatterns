//
// Created by xfc on 2018/8/4.
//
#include <iostream>
#include "../CommandPattern/CommandPattern.h"
void test() {
    Receiver receiver;
    ConcreteCommand command(&receiver);
    Invoker invoker;
    invoker.setCommand(&command);
    invoker.execCommand();
}
int main() {
    test();
    return 0;
}

