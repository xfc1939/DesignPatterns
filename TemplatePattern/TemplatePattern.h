#ifndef TEMPLATEPATTERN_H
#define TEMPLATEPATTERN_H

#include <iostream>
#include <string>
class TemplatePatternBase {
public:
	TemplatePatternBase() = default;
	virtual ~TemplatePatternBase() = default;
public:
	void outputResult() {
		std::cout << "result is " << result() << std::endl;
	}
	virtual std::string result(){ return std::string(); }
};

class TemplatePatternA :public TemplatePatternBase {
public:
	TemplatePatternA() = default;
	~TemplatePatternA() = default;
public:
	std::string result() {
		return std::string("A");
	}
};

class TemplatePatternB :public TemplatePatternBase {
public:
	TemplatePatternB() = default;
	~TemplatePatternB() = default;
public:
	std::string result() {
		return std::string("B");
	}
};

#endif