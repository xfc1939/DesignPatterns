//
// Created by xfc on 2018/6/15.
//

#include "StrategyContext.h"

void StrategyContext::createInstance(const std::string &str) {
    SimpleFactoryContext context;
    if (m_base) {
        delete m_base;
    }
    m_base = context.createInstance(str);
}
void StrategyContext::getResult() {
    if (m_base) {
        m_base->getResult();
    }
}
