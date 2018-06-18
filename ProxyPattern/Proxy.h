//
// Created by xfc on 2018/6/18.
//

#ifndef DESIGNPATTERNS_PROXY_H
#define DESIGNPATTERNS_PROXY_H

#include <iostream>

class Subject {
public:
    Subject() = default;
    virtual ~Subject() = default;

public:
    virtual  void request() {
        std::cout << "subject" << std::endl;
    }
};

class RealSubject : public Subject {
public:
    RealSubject() = default;
    ~RealSubject() override = default;

public:
    void request() override {
        std::cout << "RealSubject" << std::endl;
    }
};

class Proxy : public Subject {
public:
    Proxy() = default;
    ~Proxy() override  = default;

public:
    void setSubject(Subject *subject) {
        m_subject = subject;
    }
    void request() override {
        if (m_subject) {
            m_subject->request();
        }
    }

private:
    Subject* m_subject;
};
#endif //DESIGNPATTERNS_PROXY_H
