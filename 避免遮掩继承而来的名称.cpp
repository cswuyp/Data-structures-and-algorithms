/**/
class Base
{
private:
	int x;
public:
	virtual void mf1()=0;
	virtual void mf1(int);
	virtual void mf2();
	void mf3();
	void mf3(double);
	......
};

class Derived:public Base
{
public:
	virtual void mf1();
	void mf3();
	void mf4();
};
/*这段代码带来的行为会让每一位第一次面对它的C++程序员大吃一惊。以作用域为基础的“名称遮掩规则”并没有改变，因此base class
内所有名为mf1和mf3的函数都被derived class内的mf1和mf3函数遮掩掉了。从名称查找观点来看，Base:mf1和Base:mf3不再被Derived继承*/
Derived d;
int x;
......
d.mf1();//没问题，调用Derived::mf1
d.mf1(x);//错误！因为Derived::mf1遮掩了Base::mf1
d.mf2();//没问题，调用Base::mf2
d.mf3();//没问题，调用Derived::mf3
d.mf3(x);//错误！因为Derived::mf3遮掩了Base::mf3

/*如你所见，上述规则都折佣，即使base classes 和derived classes 内的函数有不同的参数类型也适用，而且不论函数是virtual
或non-virtual 一体适用。*/

/*你可以使用using 声明式达成目标：*/
class Base
{
private:
	int x;
public:
	virtual void mf1()=0;
	virtual void mf1(int);
	virtual void mf2();
	void mf3();
	void mf3(double);
	......
};

class Derived:public Base
{
public:
	using Base::mf1;//让Base class 内名为mf1和mf3的所有东西在Derived作用域内都可见
	using Base::mf3;
	virtual void mf1();
	void mf3();
	void mf4();
	......
};

/*现在，继承机制像往昔一样地运作:*/

Derived d;
int x;
......
d.fm1();//仍然没问题，仍然调用Derived::mf1
d.mf1(x);//现在没问题了，调用Base::mf1
d.mf2();//仍然没有问题，仍然调用Base::mf2
d.mf3();//没有问题，调用Derived：：mf3
d.mf3(x);//现在没有问题了，调用Base::mf3

/*这意味如果你继承base class 并加上重载函数，而你又希望重新定义或覆写（推翻）其中的一部分，那么你必须为那些原本会被
遮掩的每个名称引入一个using声明式，否则某些你希望继承的名称会被遮掩。*/

/*有时候你并不想继承base classes的所有函数，这是可以理解的。例如：假设Derived以private形式继承Base，而Derived唯一
想继承的mf1是那个无参版本。using声明式在这里派不上用场，因为using声明式会令继承而来的某给定名称之所有同名函数在derived
class 中都可见。不，我们需要不同的技术，即一个简单的转换函数*/
class Base
{
public:
	virtual void mf1()=0;
	virtual void mf1(int);
	......//与之前相同
};

class Derived：private Base
{
public:
	virtual void mf1()//转换函数
	{
		Base::mf1();
	}
};
......

Derived d;
int x;
d.mf1();//很好，调用的是Derived::mf1
d.mf1(x);//错误！Base::mf1()被遮掩了

/**/