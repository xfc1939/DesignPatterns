#pragma once
#include "SimpleFactoryBase.h"
class InstanceA : public SimpleFactoryBase
{
public:
	InstanceA();
	~InstanceA();
public:
	int getResult();
};

