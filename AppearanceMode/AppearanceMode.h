#ifndef APPEARANCEMODE_H
#define APPEARANCEMODE_H
// Ϊ��ϵͳ��һ��ӿ��ṩһ��һ�µĽ��棬��ģʽ������һ���߲�ӿڣ�����ӿ�ʹ����һ����ϵͳ������ʹ�á�
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