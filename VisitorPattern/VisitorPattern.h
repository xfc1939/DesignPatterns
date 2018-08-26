//
// Created by xfc on 2018/8/22.
//

#ifndef DESIGNPATTERNS_VISITORPATTERN_H
#define DESIGNPATTERNS_VISITORPATTERN_H

// 访问者模式：表示一个作用于某对象结构中的各元素操作。它使你可以在不改变各元素的类的前提下
// 定义作用于这些元素的新操作

// 访问者模式适用于数据结构相对稳定的系统
// 将数据结构和作用于数据结构上的操作之间的耦合解脱开，使得操作集合可以相对自由的演化
// 系统有比较稳定的数据结构，又有易于变化的算法的话，使用访问者模式就是比较合适的，因为
// 访问者模式使得算法操作的增加变得容易

// 访问者模式的缺点：使增加新的数据结构变得更加困难。

#include <iostream>

class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
    Visitor() = default;
    virtual ~Visitor() = default;

public:
    virtual void  visitConcreteElementA(ConcreteElementA* a) = 0;
    virtual void  visitConcreteElementB(ConcreteElementB* b) = 0;
};

class ConcreteVistorA : public Visitor{
public:
    ConcreteVistorA() = default;
    ~ConcreteVistorA() override  = default;

public:
    void visitConcreteElementA(ConcreteElementA* a) {
        std::cout << __FUNCTION__ << " a";
    }

    void  visitConcreteElementB(ConcreteElementB* b) {
        std::cout << __FUNCTION__ << " b";
    }
};

class Element {
public:
    Element() = default;
    virtual ~Element() = default;

public:
    virtual void accept(Visitor *visitor)  = 0;
};

class ConcreteElementA :public Element {
public:
    ConcreteElementA() = default;
    ~ConcreteElementA() override = default;

public:
    void accept(Visitor *visitor) override {
        visitor->visitConcreteElementA(this);
    }
};

class ConcreteElementB :public Element {
public:
    ConcreteElementB() = default;
    ~ConcreteElementB() override = default;

public:
    void accept(Visitor *visitor) override {
        visitor->visitConcreteElementB(this);
    }
};

#endif //DESIGNPATTERNS_VISITORPATTERN_H
