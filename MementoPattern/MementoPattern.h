//
// Created by xfc on 2018/7/12.
//

/**
 * 备忘录模式
 * 说明：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态
 *      这样以后就可将这个对象恢复到原先保存的状态。
 */

#ifndef DESIGNPATTERNS_MEMENTOPATTERN_H
#define DESIGNPATTERNS_MEMENTOPATTERN_H

#include <iostream>

class Memento {
public:
    Memento() :state_(){}
    virtual ~Memento() = default;

public:
    void setState(int state) {
        state_ = state;
    }
    int getState() const {
        return state_;
    }
private:
    int state_;
};
class Originator
{
public:
    Originator():state_(){}
    virtual ~Originator() = default;

    void setState(int state) {
        state_ = state;
    }
    void showState() {
        std::cout << __FUNCTION__ << " state is " << state_ << std::endl;
    }
    virtual Memento createMemento() {
        Memento memento;
        memento.setState(state_);
        return memento;
    }
    virtual  void setMemento(const Memento &memento) {
        state_ = memento.getState();
    }
private:
    int state_;
};

class CareTaker
{
public:
    CareTaker() = default;
    virtual ~CareTaker() = default;

public:
    void setMemento(const Memento &memento) {
        memento_ = memento;
    }
    Memento getMemento() {
        return memento_;
    }
private:
    Memento memento_;
};

#endif //DESIGNPATTERNS_MEMENTOPATTERN_H
