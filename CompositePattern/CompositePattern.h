//
// Created by xfc on 2018/7/14.
//

/*
 * 组合模式
 * 将对象组合成树形结构以表示部分-整体的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性。
 *
 * 什么时候用组合模式
 * 当你发现需求中是体现部分与整体层次的结构时，以及你希望用户可以忽略组合对象和单个对象的不同，统一的使用
 * 组合结构中的所有对象时，就应该考虑组合模式了。
 */

#include <list>
#include <string>
#include <iostream>

class Component {
public:
    explicit  Component(const std::string &name) :name_(name) {}
    virtual ~Component() = default;

public:
    virtual void add (Component* component) = 0;
    virtual void remove(Component* component) = 0;
    virtual void display(int depth) = 0;

protected:
    std::string name_;
};

class Leaf :public Component {
public:
    explicit  Leaf(const std::string &name):Component(name) {}
    ~Leaf () override = default;

public:
    void add(Component* component) override {}
    void remove(Component* component) override {}
    void display(int depth) override {
        std::cout << __FUNCTION__ << " "<< name_ << " " << depth <<std::endl;
    }

private:
};

class Composite : public Component {
public:
    explicit Composite(const std::string &name) : Component(name) {}

public:
    void add(Component* component) override {
        child_.push_back(component);
    }
    void remove(Component* component) override  {
        child_.remove(component);
    }

    void display(int depth) override {
        std::string str("-", depth);
        std::cout << __FUNCTION__ << "" << name_ << " "<< str << " " << depth << std::endl;
        for(Component *component : child_) {
            component->display(depth + 2);
        }
    }

private:
    std::list<Component*> child_;
};