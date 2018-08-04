//
// Created by xfc on 2018/8/3.
//

#include "../BridgePattern/BridgePattern.h"

void test() {
    ImplementorA a;
    ImplementorB b;

    Abstraction *astr = new RefindAbstraction();
    astr->setImpl(&a);
    astr->oper();
    astr->setImpl(&b);
    astr->oper();

}

int main() {
    test();
    return 0;
}