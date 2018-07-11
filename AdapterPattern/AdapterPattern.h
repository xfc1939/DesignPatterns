//
// Created by xfc on 2018/7/11.
//
/*
 * 适配器模式
 * 说明：将一个类的接口转换成客户希望的另外一个接口。
 * Adapter模式使得原本由于接口不兼容而不能一起工作的那些类一起工作。
 *
 */

#ifndef DESIGNPATTERNS_ADAPTERPATTERN_H
#define DESIGNPATTERNS_ADAPTERPATTERN_H

class Target {
public:
    Target() = default;
    virtual  ~Target() = default;

public:
    virtual void Request(){}
};

class Adaptee {
public:
    Adaptee() = default;
    virtual ~Adaptee() = default;

public:
    void specificRequest(){
        
    }
};
#endif //DESIGNPATTERNS_ADAPTERPATTERN_H
