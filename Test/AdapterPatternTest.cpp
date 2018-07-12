//
// Created by xfc on 2018/7/11.
//

#include "../AdapterPattern/AdapterPattern.h"

int main() {
    Target *target = new Adapter();
    target->Request();
    return 0;
}