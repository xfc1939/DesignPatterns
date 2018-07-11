//
// Created by xfc on 2018/7/11.
//
/**
 * 状态模式
 * 说明：当一个对象的内在状态改变时允许改变其行为，这个对象看起来更像是改变了其类
 *
 */
#ifndef DESIGNPATTERNS_STATUSPATTERN_H
#define DESIGNPATTERNS_STATUSPATTERN_H

#include <iostream>
#include <string>

class Context;

class Status {
public:
    Status() = default;
    virtual ~Status() = default;

public:
    virtual void handler(Context* context){}
    virtual std::string getName() = 0;
};

class Context {
public:
    Context():status_(){}
    virtual ~Context() = default;

public:
    void setStatus(Status *status) {
        std::cout << __FUNCTION__ << " " << "name " << status->getName() << std::endl;
        status_ = status;
    }

public:
    void request() {
        status_->handler(this);
    }

private:
    Status *status_;
};



class StatusA : public Status {
public:
    StatusA() = default;
    ~StatusA() override  = default;

public:
    void handler(Context* context) override ;
    std::string getName() override ;
};

class StatusB : public Status {
public:
    StatusB() = default;
    ~StatusB() override  = default;

public:
    void handler(Context* context) override ;
    std::string getName() override ;
};

#endif //DESIGNPATTERNS_STATUSPATTERN_H
