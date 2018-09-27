/*假设我告诉你，class D是由class B以public形式派生而来，class B 定义有一个public成员函数mf。由于mf的参数和返回值否不重要，
所以我假设两者皆为void 换句话说我的意思是:*/
class B
{
public:
	void mf();
	......
};

class D:public B{.....};
/*虽然我们对B,D和mf一无所知，但面对一个类型未D的对象x:*/
D x;//x是一个类型未D的对象
/*如果以下行为:*/
B* pb=&x;//获得一个指针指向x
pb->mf();//经由该指针调用mf

/*异于以下行为:*/
D* pD=&x;//获得一个指针指向x
pD->mf();//经由该指针调用mf

/*你可能会相当惊讶。毕竟两者都通过对象x调用成员函数mf。由于两者所调用的函数都相同，凭借的对象也相同，所以行为也应该相同
，是吗？
是的，理应如此，但事实可能不是如此。更明确的说，如果mf是个non-virtual函数而D定义有自己的版本，那就不是如此:*/

class D:public B
{
public:
	void mf();//遮掩了B::mf
	......
};
pb->mf();//调用B::mf
pD->mf();//调用D::mf

/*造成此一两面行为的原因是，non-virtual函数如B::mf和D::mf都是静态绑定，这意思是，由于pb被声明为一个public-to-B,
通过pb调用的non-virtual函数永远是B所定义的版本，即使pb指向一个类型未“B派生之class”的对象，一如本例*/

/*但另一方面，virtual函数却是动态绑定(dynamically bound),所以它们不受这个问题之苦。如果mf是一个virtual函数，不论
是通过pb或pD调用mf，都会导致调用D::mf，因为pb和pD真正指的都是一个类型为D的对象*/