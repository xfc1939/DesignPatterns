//
// Created by xfc on 2018/6/18.
//

#ifndef DESIGNPATTERNS_FACTORYMETHODPATTERN_H
#define DESIGNPATTERNS_FACTORYMETHODPATTERN_H

#include <iostream>

class  Operatorion {
public:
    Operatorion() = default;
    virtual ~Operatorion() = default;

public:
    virtual void getResult() {
        std::cout << "Operatorion" << std::endl;
    }
};


class  OperatorionA : public Operatorion
{
public:
    OperatorionA() = default;
    virtual ~OperatorionA() = default;

public:
    virtual void getResult() {
        std::cout << "OperatorionA" << std::endl;
    }
};

class  OperatorionB : public Operatorion
{
public:
    OperatorionB() = default;
    virtual ~OperatorionB() = default;

public:
    virtual void getResult() {
        std::cout << "OperatorionB" << std::endl;
    }
};

class IFactory {
public:
    IFactory() = default;
    virtual  ~IFactory() = default;

public:
    virtual  Operatorion* createOperatorion() {
        return nullptr;
    }
};

class IFactoryA : public IFactory
{
public:
    IFactoryA() = default;
    ~IFactoryA() override = default;

public:
     Operatorion* createOperatorion() override {
        return new OperatorionA();
    }
};

class IFactoryB : public IFactory
{
public:
    IFactoryB() = default;
    ~IFactoryB() override = default;

public:
    Operatorion* createOperatorion() override {
        return new OperatorionB();
    }
};


#endif //DESIGNPATTERNS_FACTORYMETHODPATTERN_H
