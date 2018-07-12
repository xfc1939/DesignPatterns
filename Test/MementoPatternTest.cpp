//
// Created by xfc on 2018/7/12.
//

#include "../MementoPattern/MementoPattern.h"

int main() {
    Originator origin;
    origin.setState(-1);
    origin.showState();

    CareTaker taker;
    taker.setMemento(origin.createMemento());

    origin.setState(1000);
    origin.showState();

    origin.setMemento(taker.getMemento());
    origin.showState();

    return 0;
}