//
// Created by xfc on 2018/8/2.
//

#include <iostream>
#include "../SingletonPattern/SingletonPattern.h"

void Test() {
    std::cout << &Singleton::getInstance() << std::endl;
    std::cout << &Singleton::getInstance() << std::endl;

}

int main() {
    Test();
    return 0;
}