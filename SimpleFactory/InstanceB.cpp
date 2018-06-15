#include <iostream>
#include "InstanceB.h"


InstanceB::InstanceB()
{
}


InstanceB::~InstanceB()
{
}

int InstanceB::getResult()
{
	std::cout << "InstanceB" << std::endl;
	return 0;
}
