
#include <iostream>

using namespace std;


/*
 桥接模式 是实现两个不同的接口 A 和 B, A接口中含有属性B接口,并通过构造器注入,在A接口的实现类型中, 可以调用 传入的 B 接口的实现类的方法, 达到 两个接口的实现类 的方法笛卡尔积的效果;
 * */

class OS {
public:
	virtual void InstallOS_impl() = 0;
};

class LinuxOS : public OS {
public:
	virtual void InstallOS_impl() { cout<<"Install Linux OS"<<endl; }
};

class WindowsOS : public OS {
public:
	virtual void InstallOS_impl() { cout<<"Install Windows OS"<<endl; }
};

class UnixOS : public OS {
public:
	virtual void InstallOS_impl() { cout<<"Install Unix OS"<<endl; }
};


class Computer {
public:
	virtual void printInfo() = 0;
	virtual void InstallOS() = 0;
};

class MAC : public Computer {
public:
	virtual void printInfo() { cout<<"This is MAC, ";}
	MAC(OS *impl) { this->impl = impl; }
	void InstallOS() { printInfo(); impl->InstallOS_impl(); };
private:
	OS *impl;
};



class Lenovo : public Computer {
public:
	virtual void printInfo() { cout<<"This is Lenovo, ";}
	Lenovo(OS *impl) { this->impl = impl; }
	void InstallOS() { printInfo(); impl->InstallOS_impl(); };
private:
	OS *impl;
};


int main()
{
	OS *os1 = new LinuxOS();
	OS *os2 = new WindowsOS();
	OS *os3 = new UnixOS();

	Computer *c1 = new MAC(os1);
	Computer *c2 = new Lenovo(os2);
	Computer *c3 = new Lenovo(os3);

	c1->InstallOS();
	c2->InstallOS();
	c3->InstallOS();

	return 0;
}

