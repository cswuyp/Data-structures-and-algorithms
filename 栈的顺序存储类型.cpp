/*栈的顺序存储类型科描述为*/
#define MaxSize 50//定义栈中元素的最大个数
typedef struct
{
	Elemtype data[MaxSize];//存放栈中元素
	int top;//栈顶指针
}SqStack;

//初始化
void InitStack(&s)
{
	s.top=-1;//初始化栈顶指针
}

//判栈空
bool StackEmpty(s)
{
	if(s.top==-1)//栈空
	{
		return true;
	}
	else//不空
	{
		return false;
	}
}

//进栈
bool push(SqStack &s,Elemtype x)
{
	if(s.top==MaxSize-1)//栈满报错
	{
		return false;
	}
	s.data[++s.top]=x;//指针先加1，再入栈
	return true;
}

//出栈
bool pop(SqStack &s,Elemtype &x)
{
	if(s.top==-1)//栈空，报错
	{
		return false;
	}
	x=s.data[s.top--];//先出栈，指针再减1
	return true;
}

//读栈顶元素
bool GetTop(SqStack s,Elemtype &x)
{
	if(s.top==-1)//栈空，报错
	{
		return false;
	}
	x=s.data[s.top];//x记录栈顶元素
	return true;
}