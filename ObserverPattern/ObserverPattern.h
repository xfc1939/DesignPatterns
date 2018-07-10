//
// Created by xfc on 2018/7/10.
//

#ifndef DESIGNPATTERNS_OBSERVERPATTERN_H
#define DESIGNPATTERNS_OBSERVERPATTERN_H
// 观察者模式 定义了一种一对多的依赖关系，让多个观察者对象同时监听某一个主题对象，这个主题对象在状态发生改变时，会通知所有观察者对象，使它
// 们能够自动更新自己。
#include <list>
#include <string>
#include <iostream>

class Subject;
class Observer {
public:
    Observer() = default;
    virtual ~Observer() = default;

public:
    virtual void onNotify(Subject *sub) = 0;
};

// 抽象的通知者
class Subject {
public:
    Subject() = default;
    virtual ~Subject() = default;
public:
    void add(Observer *observer) {
        observers_.push_back(observer);
    }
    void remove(Observer *observer) {
        observers_.remove(observer);
    }
    virtual std::string getState() = 0;
    void notify() {
        for(Observer *ob : observers_) {
            ob->onNotify(this);
        }
    }

private:
    std::list<Observer*> observers_;
};

class ConcreteObserver :public Observer {
public:
    explicit  ConcreteObserver(const std::string &name)
    : name_(name)
    {}
    void onNotify(Subject *sub) override {
        if (sub == nullptr) return;
        std::cout << __FUNCTION__ << " " << name_ << " " << sub->getState() << std::endl;
    }
private:
    std::string name_;
};




class ConcreteSubject : public Subject {
public:
    explicit ConcreteSubject (const std::string &state)
        : state_(state)
    {}
    ~ConcreteSubject() = default;
    std::string getState() {
        return state_;
    }
private:
    std::string state_;
};
#endif //DESIGNPATTERNS_OBSERVERPATTERN_H
