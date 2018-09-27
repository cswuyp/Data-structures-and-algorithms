/*从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，如果s或t不合理或者顺序表为空则显示出错误信息并退出运行*/

//参考答案
bool ListDelete(SqList &L,ElemType s,ElemType t)//注意这是个有序表，所以并不需要每次查找都把表遍历一遍，只需要查找到表从哪里开始大于s大于t就可以了
{
	int i,j;
	if(s>=t||L.lenght==0)
	{
		return false;
	}
	for(i=0;i<L.lenght&&L.data[i]<s;i++);//寻找值大于等于s的第一个元素
	if(i>=L.lenght)
	{
		return false;//所有元素值均小于s，则返回
	}
	for(j=i;j<L.lenght&&L.data[j]<=t;j++);//寻找值>t的第一个元素
	for(;j<L.lenght;i++,j++)//i不需要控制范围是因为i是在j前面的位置，所以只要控制j的范围就可以了，而且最后i的值等于多少并不知，是程序的输出结果的值
	{
		L.data[i]=L.data[j];//前移，填补被删除元素的位置
	}
	L.lenght=i;
	return true;
}