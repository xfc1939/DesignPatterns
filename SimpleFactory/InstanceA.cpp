#include <iostream>
#include "InstanceA.h"

InstanceA::InstanceA()
{
}


InstanceA::~InstanceA()
{
}

int InstanceA::getResult() {
	std::cout << "InstanceA" << std::endl;
	return 0;
}