//
// Created by xfc on 2018/6/18.
//

#ifndef DESIGNPATTERNS_COMPONENT_H
#define DESIGNPATTERNS_COMPONENT_H

#include <iostream>

class Component {
public:
    Component() = default;
    virtual  ~Component() = default;

public:
    virtual void operator()() {
        std::cout << "component" << std::endl;
    }
};

class ConcreteComponent :public Component
{
public:
    ConcreteComponent() = default;
    ~ConcreteComponent() override = default;

public:
    void operator()() override {
        std::cout << "ConcreteComponent" << std::endl;
    }
};

class Decorator : public Component
{
public:
    Decorator() = default;
    ~Decorator() override = default;

public:

    void operator()() override {
        if (m_component) {
            m_component->operator()();
        }
        std::cout << "Decorator" << std::endl;
    }

public:
    void setComponent(Component *component) {
        m_component = component;
    }

private:
    Component *m_component;
};

class DecoratorA : public  Decorator
{
public:
    DecoratorA() = default;
    ~DecoratorA() override = default;

public:
    void operator()() override {
        Decorator::operator()();
        A();
    }

private:
    void A() {
        std::cout << "DecoratorA" << std::endl;
    }
};

class DecoratorB : public  Decorator
{
public:
    DecoratorB() = default;
    ~DecoratorB() override = default;

public:
    void operator()() override {
        Decorator::operator()();
        B();
    }

private:
    void B() {
        std::cout << "DecoratorB" << std::endl;
    }
};

#endif //DESIGNPATTERNS_COMPONENT_H
