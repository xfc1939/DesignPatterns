#ifndef PROTOTYPEBASE_H
#define PROTOTYPEBASE_H

#include <iostream>

class PrototypeBase {
public:
	PrototypeBase() = default;
	virtual ~PrototypeBase() = default;

public:
	virtual PrototypeBase *clone() = 0;
	virtual void print(){}
};

class PrototypeBaseA : public PrototypeBase {
public:
	PrototypeBaseA(int value) : m_value(value) {}
	PrototypeBaseA(const PrototypeBaseA &a) {
		m_value = a.m_value;
	}
	~PrototypeBaseA() {
		std::cout << "PrototypeBaseA" << std::endl;
	}

public:
	PrototypeBase *clone() override {
		return new PrototypeBaseA(*this);
	}

	void print() override {
		std::cout << "value " << m_value << std::endl;
	}

private:
	int m_value;
};

#endif