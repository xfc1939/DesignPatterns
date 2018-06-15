// SimpleFactory.cpp : 定义控制台应用程序的入口点。
//
#include <cstdio>
#include <iostream>
#include "SimpleFactoryContext.h"

int main(int argc, char* argv[])
{
	SimpleFactoryContext context;
	SimpleFactoryBase *base = context.createInstance("A");
	base->getResult();

	SimpleFactoryBase *base1 = context.createInstance("B");
	base1->getResult();

	int i;
	std::cin >> i;
	return 0;
}

