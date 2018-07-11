//
// Created by xfc on 2018/7/11.
//

#include "../StatusPattern/StatusPattern.h"
int main() {
    auto context = new Context;
    context->setStatus(new StatusA);
    context->request();
    context->request();
    context->request();
    context->request();
    return 0;
}