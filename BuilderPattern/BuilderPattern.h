//
// Created by xfc on 2018/7/3.
//

#ifndef DESIGNPATTERNS_BUILDERPATTERN_H
#define DESIGNPATTERNS_BUILDERPATTERN_H
// 抽象接口
#include <iostream>
#include <string>
#include <list>

class Product {
public:
    Product() = default;
    virtual ~Product() = default;

public:
    void addPart(const std::string &part) {
        m_part.push_back(part);
    }
    void show() {
        for(const std::string &str : m_part) {
            std::cout << str << std::endl;
        }
    }
private:
    std::list<std::string> m_part;
};
class Builder {
public:
    Builder() = default;
    virtual ~Builder() = default;
public:
    virtual void buildA() = 0;
    virtual void buildB() = 0;
    virtual Product* getResult() = 0;
};

class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder():m_product(nullptr) {
        m_product = new Product();
    };
    ~ConcreteBuilder() = default;

public:
    void buildA() {
        m_product->addPart("buildA");
    }
    void buildB() {
        m_product->addPart("buildB");
    }
    Product* getResult() {
        return m_product;
    }
private:
    Product* m_product;
};

// 指挥者类，用来具体构造用的
class Director {
    static void construct( Builder& builder) {
        builder.buildA();
        builder.buildB();
    }
};

#endif //DESIGNPATTERNS_BUILDERPATTERN_H
