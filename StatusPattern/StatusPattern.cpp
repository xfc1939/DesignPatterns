//
// Created by xfc on 2018/7/11.
//

#include "StatusPattern.h"


void StatusA::handler(Context *context) {
    context->setStatus(new StatusB);
}

std::string StatusA::getName() {
    return  "A";
}

std::string StatusB::getName() {
    return  "B";
}

void StatusB::handler(Context *context) {
    context->setStatus(new StatusA);
}