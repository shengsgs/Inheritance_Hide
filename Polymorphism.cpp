#include<iostream>
using namespace std;

class A
{
public:
	void foo()
	{
		cout<<"1"<<endl;
	}
	virtual void fun()
	{
		cout<<"2"<<endl;
	}
};

class B : public A
{
public:
	void foo()
	{
		cout<<"3"<<endl;
	}
	void fun()
	{
		cout<<"4"<<endl;
	}
};

int main()
{
	A a;
	B b;
	A *p = &a;
	cout<<"a-foo:";
	p->foo();
	cout<<"a-fun:";
	p->fun();

	p = &b;
	cout<<"b-foo:";
	p->foo();
	cout<<"b-fun:";
	p->fun();

	cout<<"a to b"<<endl;
	B *ptr = (B *)&a;
	ptr->foo();//cout------3，不是虚函数
	ptr->fun();//cout------2 是虚函数

	B bb;
	cout<<"b to a"<<endl;
	A *ptr2 = (A *)&bb;
	ptr2->foo();//cout-----1 不是虚函数
	ptr2->fun();//cout-----4 是虚函数
	return 0;
}
