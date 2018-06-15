#include "SimpleFactoryContext.h"


SimpleFactoryContext::SimpleFactoryContext()
{
}


SimpleFactoryContext::~SimpleFactoryContext()
{
}

SimpleFactoryBase* SimpleFactoryContext::createInstance(const std::string &str) {

	SimpleFactoryBase* result = NULL;
	
	if (str == "A") {
		result = new InstanceA();
	} else if (str == "B") {
		result = new InstanceB();
	}
	return result;
}
