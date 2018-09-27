/*按值查找*/
/*在顺序表L中查找第一个元素值等于e的元素，并返回其位序*/
int LocateElem(SqList L,ElemType e)
{
	//实现查找顺序表中值为e的元素，如果查找成功，返回元素位序，否则返回0
	int i;
	for(i=0;i<L.length;i++)
	{
		if(L.data[i]==e)
		{
			return i+1;//下标为i的元素值等于e，返回位序为i+1
		}
		return 0;//退出循环，说明查找失败
	}
}