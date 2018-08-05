//
// Created by XFC on 2018/8/5.
//

#ifndef DESIGNPATTERNS_AGENCYPATTERN_H
#define DESIGNPATTERNS_AGENCYPATTERN_H

/*
 * 中介者模式
 *尽管将一个系统分割成许多对象通常可以增加其可复用性，但是对象间相互连接的激增又会降低
 * 其可复用性。
 * 中介者模式介绍：
 * 用一个中介对象来封装一些列的对象交互，中介者使
 * 各对象不需要显示地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。
 */
// 中介者
#include <iostream>
#include <string>
class Colleague;
class Mediator {
public:
    Mediator() = default;
    virtual ~Mediator() = default;

public:
    virtual void sendMessage(const std::string &msg, Colleague * colleague) = 0;
};

class Colleague {
public:
    Colleague() : mediator_(nullptr){}
    virtual ~Colleague() = default;

public:
    void setMediator(Mediator *mediator) {
        mediator_ = mediator;
    }
    // 大话设计模式书中，这个方法并没有在Colleague类实现
    // 而是在其子类中实现的
    virtual void  sendMessage(const std::string &msg) {
        if (mediator_) {
            mediator_->sendMessage(msg, this);
        }
    }
protected:
    Mediator *mediator_;
};

class Colleague1 :public Colleague {
public:
    Colleague1() = default;
    ~Colleague1() override = default;

public:
    void notify(const std::string &msg) {
        std::cout << __FUNCTION__ << " colleague1 receive message from other colleague " << msg << std::endl;
    }
};

class Colleague2 :public Colleague {
public:
    Colleague2() = default;
    ~Colleague2() override = default;

public:
    void notify(const std::string &msg) {
        std::cout << __FUNCTION__ << " colleague2 receive message from other colleague " << msg << std::endl;
    }
};

class ConcreteMediator : public Mediator {
public:
    ConcreteMediator(Colleague1 *colleague1, Colleague2 *colleague2):colleague1_(colleague1), colleague2_(colleague2) {}
    ~ConcreteMediator() override = default;
public:
    void sendMessage(const std::string &msg, Colleague *colleague) override  {
        if (colleague == colleague1_) {
            colleague2_->notify(msg);
        } else {
            colleague1_->notify(msg);
        }
    }
private:
    Colleague1 *colleague1_;
    Colleague2 *colleague2_;
};

#endif //DESIGNPATTERNS_AGENCYPATTERN_H
