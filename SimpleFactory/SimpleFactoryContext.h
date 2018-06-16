#pragma once
#include <string>
#include "FactoryInstance.h"
#include "SimpleFactoryBase.h"
#ifndef TEMPLATE
class SimpleFactoryContext
{
public:
	SimpleFactoryContext();
	~SimpleFactoryContext();
public:
	SimpleFactoryBase* createInstance(const std::string &str);
};
#else

#endif


