#pragma once
#include <string>
#include "FactoryInstance.h"
#include "SimpleFactoryBase.h"

class SimpleFactoryContext
{
public:
	SimpleFactoryContext();
	~SimpleFactoryContext();
public:
	SimpleFactoryBase* createInstance(const std::string &str);
};

