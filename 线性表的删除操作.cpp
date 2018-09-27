/*线性表的删除操作*/
/*删除顺序表L中第i（1<=i<=L.length）个位置的元素，成功则返回true，并将被删除的元素用引用变量e返回，否则返回false*/
bool ListDelete(SqList &L,int i,int e)
{
	//实现删除顺序表L中第i个位置的元素
	if(i<1||i>L.length)//判断i的范围是否有效
	{
		return false;
	}
	e=L.data[i-1];//将被删除的元素赋值给e
	for(int j=i;j<L.length;j++)//将第1个位置之后的元素前移
	{
		L.data[j-1]=L.data[j];
	}
	L.length--;//线性表长度减1
	return true;
}