//
// Created by xfc on 2018/8/22.
//

#include "../InterpreterPattern/InpterpreterPattern.h"

#include <list>

void test()
{
    std::list<AbstractExpression*> abstractLit;
    abstractLit.push_back(new TerminalExpression());
    abstractLit.push_back(new NoneTerminalExpression());
    abstractLit.push_back(new TerminalExpression());
    abstractLit.push_back(new TerminalExpression());

    Context context;
    for(AbstractExpression* expression : abstractLit) {
        expression->interpreter(&context);
    }
}

int main() {
    test();
    return 0;
}