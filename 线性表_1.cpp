/*从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错误
信息并退出运行*/
/*算法思想：搜索整个顺序表，查找最小值元素并记住其位置，搜索结束后用最后一个元素填补空出的的原最小值元素位置*/
bool Min(SqLite &L,Elemtype &value)
{
	//删除顺序表L中最小值元素结点，并通过引用型参数value返回其值
	//如果删除成功，返回true；否则，返回false
	if(L.length==0)
	{
		return false;//表空，终止操作返回fasle
	}
	value=L.data[0];//用表的第一个元素最为比教的初值
	int pos=0;
	for(int i=1;i<=L.length;i++)//循环，寻找具有最小值的元素（因为前面已经把表的第一个元素赋值给了value所以此时比教从表的第二个元素开始）
	{
		if(L.data[i]<value)
		{
			value=L.data[i];
			pos=i;
		}
	}
	L.data[pos]=L.data[L.length-1];//空出的位置由最后一个元素填补
	L.length--;
	return true;//此时，value即为最小值
}