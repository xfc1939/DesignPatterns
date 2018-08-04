//
// Created by xfc on 2018/8/3.
//

#ifndef DESIGNPATTERNS_BRIDGEPATTERN_H
#define DESIGNPATTERNS_BRIDGEPATTERN_H

/*
 * 桥接模式
 */
#include <iostream>
class Implementor {
public:
    Implementor() = default;
    virtual ~Implementor() = default;
    virtual void oper() = 0;
};

class ImplementorA :public Implementor {
public:
    ImplementorA() = default;
    ~ImplementorA() override = default;

public:
    void oper() override  {
        std::cout << __FUNCTION__ << " implementorA" << std::endl;
    }
};

class ImplementorB :public Implementor {
public:
    ImplementorB() = default;
    ~ImplementorB() override = default;

public:
    void oper() override  {
        std::cout << __FUNCTION__ << " implementorB" << std::endl;
    }
};

class Abstraction {
public:
    explicit Abstraction():impl_(nullptr){}
    void setImpl(Implementor *impl) {
        impl_ = impl;
    }

    virtual  ~Abstraction() = default;
    virtual void oper() {
        if (impl_) {
            impl_->oper();
        }
    }
protected:
    Implementor *impl_;
};

class RefindAbstraction: public Abstraction
{
public:
    explicit RefindAbstraction() : Abstraction(){}
    ~RefindAbstraction() override = default;

public:
    void oper() override  {
        impl_->oper();
    }
};


#endif //DESIGNPATTERNS_BRIDGEPATTERN_H
