/*线性表的插入操作*/
bool ListInsert(SqList &L,int i,ElemType e)
{
	//算法实现将元素e插入到顺序表L中第i个位置
	if(i<1||i>L.length+1)//判断i的范围是否有效,当i=L.length+1时相当于在表尾追加
	{
		return false;
	}
	if(L.length>=MaxSize)//当前存储空间已满，不能插入
	{
		return false;
	}
	for(int j=L.length;j>=i;j--)//将第i个元素及之后的元素后移
	{
		L.data[j]=L.data[j-1];//表的长度为lenght但是实际上表的数组下标是lenght-1，所以表的最后一个元素下标为j-1
	}
	L.data[i-1]=e;//在位置i处放入e
	L.length++;//线性表长度加1
	return true;
}