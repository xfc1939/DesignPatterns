//
// Created by XFC on 2018/8/5.
//

#include "../ChainPattern/ChainPattern.h"
void test() {
    BigBoss bigBoss(nullptr);
    SmallBoss smallBoss(&bigBoss);
    smallBoss.action(1);
    smallBoss.action(20);
    smallBoss.action(23);
}

int main() {
    test();
    return 0;
}