/*长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素*/
/*bool ListDelete(SqList &L,int x)
{
	if(L.length==0)
	{
		return false;
	}
	for(int i=0;i<=L.length;i++)
	{
		if(L.data[i]==x)
		{
			for(int j=i;j<=length;j++)
			{
				L.data[j-1]=L.data[j];
			}
			L.length--;//这里是否有问题？待验证（用这种方法当线性表中等于x的值很少时，时间会更少）
		}
	}
	return true;
}*/
//参考答案
void ListDelete(SqList &L,Elemtype x)
{
	int k=0;//记录不等于x的元素的个数
	for(i=0;i<L.length;i++)
	{
		if(L.data[i]!=x)
		{
			L.data[k]=L.data[i];
			k++;//不等于x的元素增1
		}
	}
	L.length=k;//顺序表L的长度等于k
}