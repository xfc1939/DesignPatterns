//
// Created by xfc on 2018/8/21.
//

#ifndef DESIGNPATTERNS_FLYWEIGHTPATTERN_H
#define DESIGNPATTERNS_FLYWEIGHTPATTERN_H

// 享元模式：运用共享技术有效的支持大量细粒度的对象


#include <iostream>
#include <string>
#include <unordered_map>
// 所有具体享元类的超类或接口，通过这个接口，Flyweight可以接受并作用于外部状态
// 享元模式的作用：
// 可以避免大量非常相似类的开销，在程序设计中，有时需要生成大量细粒度的类实例来表示数据。如果能够
// 发现这些实例除了几个参数外基本相同的，有时就能够大幅度地减少需要实例化的类的数量。如果能够把这些参数
// 移植到类实例的外部，在方法调用时将它传递进来，就可以通过共享大幅度地减少单个实例的数目
class Flyweight {
public:
    Flyweight() = default;
    virtual ~Flyweight() = default;

public:
    virtual void operation(int extrinsicstate) = 0;
};

class ConcreteFlyweight : public Flyweight
{
public:
    ConcreteFlyweight() = default;
    ~ConcreteFlyweight() override = default;

public:
    void operation(int extrinsicstate) override {
        std::cout << "shared " <<__FUNCTION__ << " " << extrinsicstate << std::endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight {
public:
    UnsharedConcreteFlyweight() = default;
    ~UnsharedConcreteFlyweight() override = default;

public:
    void operation(int extrinsicstate) override  {
        std::cout << "unshared " <<__FUNCTION__ << " " << extrinsicstate << std::endl;
    }
};


class FlyweightFactory {
public:
    FlyweightFactory() {
        m_hashtable.insert(std::make_pair<std::string, Flyweight*>("X", new ConcreteFlyweight));
        m_hashtable.insert(std::make_pair<std::string, Flyweight*>("Y", new ConcreteFlyweight));
        m_hashtable.insert(std::make_pair<std::string, Flyweight*>("Z", new ConcreteFlyweight));

    }
    ~FlyweightFactory() = default;

public:
    Flyweight* getFlyweight(const std::string &key) {
        return m_hashtable.at(key);
    }

private:
    std::unordered_map<std::string, Flyweight*> m_hashtable;
};

#endif //DESIGNPATTERNS_FLYWEIGHTPATTERN_H
