#ifndef APPEARANCEMODE_H
#define APPEARANCEMODE_H
// 为子系统的一组接口提供一个一致的界面，次模式定义了一个高层接口，这个接口使得这一个子系统更容易使用。
#include <iostream>
class InnerOper {
public:
	InnerOper() = default;
	~InnerOper() = default;
public:
	void oper(){
		std::cout << "inneroper::oper()" << std::endl;
	}
};

class InnerOper1 {
public:
	InnerOper1() = default;
	~InnerOper1() = default;
public:
	void oper(){
		std::cout << "inneroper1::oper()" << std::endl;
	}
};


class AppearanceMode {
public:
	AppearanceMode() = default;
	~AppearanceMode() = default;
	void oper() {
		std::cout << "AppearanceMode::oper()" << std::endl;
		m_oper.oper();
		m_oper1.oper();
	}
private:
	InnerOper m_oper;
	InnerOper1 m_oper1;
};

#endif