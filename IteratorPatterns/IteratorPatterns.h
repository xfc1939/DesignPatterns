//
// Created by xfc on 2018/7/31.
//

#ifndef DESIGNPATTERNS_ITERATORPATTERNS_H
#define DESIGNPATTERNS_ITERATORPATTERNS_H

/*
 * 迭代器模式
 * 什么时候需要用迭代器模式
 * 当你需要访问一个聚类对象，而且不管这些对象是什么都需要遍历的时候，你就应该考虑使用迭代器模式。
 *
 * 为遍历不同的聚类结构提供如开始、下一个、是否结束、当前哪一项等统一的接口。
 *
 * 迭代器模式就是分离了集合对象的遍历行为，抽象出一个迭代器类类负责，这样既可以做到不暴露集合的内部结构，
 * 又可以让外部代码透明的访问集合内部的数据
 */

#include <vector>
#include <iostream>

template <class T>
class Iterator {
public:
    Iterator() = default;
    virtual ~Iterator() = default;

public:
    virtual  T* first() = 0;
    virtual  T* next() = 0;
    virtual  bool isDone() = 0;
    virtual  T* currentItem() = 0;
};

template <class T>
class Aggregate  {
public:
    Aggregate() = default;
    virtual ~Aggregate() = default;

public:
    virtual Iterator<T>* CreateIterator() = 0;
};

template <class T>
class ConcreteAggregate : public Aggregate<T> {
public:
    explicit  ConcreteAggregate(int size) {
        m_vector.resize(size);
    }
    ~ConcreteAggregate() override = default;

public:
    int count() {
        return m_vector.size();
    }
    T& operator[](int index) {
        return m_vector.at(index);
    }

    Iterator<T>* CreateIterator() override ;
private:
    std::vector<T> m_vector;
};
template <class T>
class ConcreteIterator : public Iterator<T> {
public:
    ConcreteIterator() = delete;
    explicit  ConcreteIterator(ConcreteAggregate<T> *aggregate)
            :aggregate_(aggregate),currentIndex_(0){}
    ~ConcreteIterator() = default;

public:
    T* first() override  {
        return &(*aggregate_)[0];
    }
    T* next() override {
        T* ret = nullptr;
        ++currentIndex_;
        if (currentIndex_ < aggregate_->count()) {
            ret = &(*aggregate_)[currentIndex_];
        }
        return ret;
    }

    T* currentItem() override{
        return &(*aggregate_)[currentIndex_];
    }

    bool isDone() override {
        return currentIndex_ >= aggregate_->count();
    }
private:
    ConcreteAggregate<T> *aggregate_;
    int currentIndex_;
};
template <class T>
Iterator<T>* ConcreteAggregate<T>::CreateIterator()  {
    return new ConcreteIterator<T>(this);
}

#endif //DESIGNPATTERNS_ITERATORPATTERNS_H
