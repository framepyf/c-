#include<iostream>
using namespace std; 
class A
{
	public: 
		~A()
		{
			cout<<"destructor A"<<endl;
		}
};

class B:public A {
	public:
		~B() {
			cout<<"destructor B"<<endl;
		}
};

/* 打印结果:
 destructor A
destructor B
destructor A
destructor A
 */
int main() {
	A a;
	A *pa = new B; 
	B *pb = new B; 
	delete pa; 
	delete pb; 
	return 0;
};
