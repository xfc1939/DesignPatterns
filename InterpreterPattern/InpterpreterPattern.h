//
// Created by xfc on 2018/8/22.
//

#ifndef DESIGNPATTERNS_INPTERPRETERPATTERN_H
#define DESIGNPATTERNS_INPTERPRETERPATTERN_H

// 解释器模式：给定一个语言，定义它的文法的一种表示，并定义一个解释器，这个解释器使用该
// 表示来解释语言中的句子
// 解释器模式解决的问题：如果一种特定类型的问题发生的频率足够高，那么就值得将该问题的各个实例表述为一个简单语言中的句子。这样就
// 可以构建一个解释器，该解释器通过解释这些句子来解决该问题。
// 正则表达式就是解释器模式的一种应用

// 解释器的一种应用：音乐解释器

#include <iostream>

class Context {

};

class AbstractExpression {
public:
    AbstractExpression() = default;
     virtual  ~AbstractExpression() = default;

public:
    virtual void  interpreter(Context *context) = 0;
};

// 终端解释器
class TerminalExpression : public AbstractExpression {
public:
    TerminalExpression() = default;
    ~TerminalExpression() override = default;

public:
    void interpreter(Context *context) override {
        std::cout << "终端解释器 " << __FUNCTION__ << std::endl;
    }
};

// 非终结符表达式
class NoneTerminalExpression : public AbstractExpression {
public:
    NoneTerminalExpression() = default;
    ~NoneTerminalExpression() override = default;

public:
    void interpreter(Context *context) override {
        std::cout << "非终端解释器 " << __FUNCTION__ << std::endl;
    }
};

// 非终端解释器
#endif //DESIGNPATTERNS_INPTERPRETERPATTERN_H
