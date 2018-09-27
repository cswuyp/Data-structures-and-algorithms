/*将两个有序顺序表合并成一个新的有序有序顺序表，并由函数返回结果顺序表*/
/*算法思想：首先，按顺序不断取下两个顺序表表头较小的结点存入新的顺序表中。
然后，看哪个表还有剩余，将剩余的部分加到新的顺序表后面*/
bool Merge(SqList A,SqList B,SqList &C)//因为要修改线性表C的值，所以这里需要引用C
{
	if(A.length+B.length>C.maxsize)
	{
		return false;
	}
	int i=0,j=0,k=0;
	while(i<A.length&&j<B.length)//循环，两两比较，小者存入结果表（满足循环条件时说明两个表都还有剩余，不满足时说明只有一个表还有剩余）
	{
		if(A.data[i]<=B.data[j])
		{
			C.data[k++]=A.data[i++];
		}
		else
		{
			C.data[k++]=B.data[j++];
		}
	}
	while(i<A.length)//还剩一个没有比较完的顺序表
	{
		C.data[k++]=A.data[i++];
	}
	while(i<B.length)
	{
		C.data[k++]=B.data[j++];
	}
	C.length=k;
	return true;
}
