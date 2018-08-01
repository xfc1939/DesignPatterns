//
// Created by xfc on 2018/7/31.
//

#include <iostream>
#include <string>
#include "../IteratorPatterns/IteratorPatterns.h"

void Test() {
    ConcreteAggregate<std::string> aggregate(3);
    aggregate[0] = "abc";
    aggregate[1] = "1235";
    aggregate[2] = "hhhhh";
    Iterator<std::string> *iter = aggregate.CreateIterator();
    while(!iter->isDone()) {
        std::cout << *(iter->currentItem()) << std::endl;
         iter->next();
    }

}

int main() {
    Test();
    return 1;
}