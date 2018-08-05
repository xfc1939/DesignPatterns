//
// Created by XFC on 2018/8/5.
//

#ifndef DESIGNPATTERNS_CHAINPATTERN_H
#define DESIGNPATTERNS_CHAINPATTERN_H

/*
 * 职责链模式
 * 使多个对象都能处理请求，从而避免请求的发送者和接收者之间的耦合关系，将这些对象连成一条链，并沿着
 * 这条链传递请求，知道有接收者能处理这个请求。
 * 该模式的好处：
 * 接收者和发送者都没有对方的明确消息，且连中的对象自己也并不知道链的结构，结果是职责连可简化对象的相互链接。
 */

#include <iostream>
class Receiver {
public:
    explicit  Receiver(Receiver *super):super_(super){}
    virtual  ~Receiver() = default;

public:
    virtual void action(int request) = 0;

protected:
    Receiver *super_;
};

class SmallBoss : public Receiver {
public:
    explicit SmallBoss(Receiver *super) : Receiver(super){}
    ~SmallBoss() override  = default;

public:
    void action(int request) override {
        if ( 0 < request && request <= 10) {
            std::cout << __FUNCTION__ << " I can deal with this request" << std::endl;
        } else if(super_) {
            super_->action(request);
        } else {
            std::cout << __FUNCTION__ << " nothing to do..." << std::endl;
        }
    }
};

class BigBoss : public Receiver {
public:
    explicit BigBoss(Receiver *super) : Receiver(super){}
    ~BigBoss() override  = default;

public:
    void action(int request) override {
        if ( 10 < request && request <= 20) {
            std::cout << __FUNCTION__ << " I can deal with this request" << std::endl;
        } else if(super_) {
            super_->action(request);
        } else {
            std::cout << __FUNCTION__ << " nothing to do..." << std::endl;
        }
    }
};

#endif //DESIGNPATTERNS_CHAINPATTERN_H
