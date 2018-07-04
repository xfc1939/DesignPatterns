//
// Created by xfc on 2018/6/18.
//
#include <cstdio>
#include <iostream>

#include "../ProxyPattern/Proxy.h"


// 代理模式测试
void ProxyTest() {
    RealSubject *subject = new RealSubject;
    Proxy *proxy = new Proxy;
    proxy->setSubject(subject);
    proxy->request();
}

int main(int argc, char* argv[])
{

    ProxyTest();
    int i;
    std::cin >> i;
    return 0;
}

