//
// Created by XFC on 2018/8/5.
//

#ifndef DESIGNPATTERNS_AGENCYPATTERNTEST_H
#define DESIGNPATTERNS_AGENCYPATTERNTEST_H

#include "../AgencyPattern/AgencyPattern.h"
#include <string>
void test() {
    Colleague2 colleague2;
    Colleague1 colleague1;
    ConcreteMediator mediator(&colleague1, &colleague2);
    colleague1.setMediator(&mediator);
    colleague2.setMediator(&mediator);
    colleague1.sendMessage("hello");
    colleague2.sendMessage("hello1");
}

int main() {
    test();
    return 0;
}
#endif //DESIGNPATTERNS_AGENCYPATTERNTEST_H
