#pragma once
#include "SimpleFactoryBase.h"
class InstanceB : public SimpleFactoryBase
{
public:
	InstanceB();
	~InstanceB();
public:
	int getResult();
};

