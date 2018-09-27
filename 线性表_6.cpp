/*从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同*/
void ListDelete(SqList &L)
{
	int i,j;//i存储第一个不相同的元素，j工作指针
	if(L.length==0)
	{
		return false;
	}
	for(i=0,j=1;j<L.length;j++)
	{
		if(L.data[i]!=L.data[j])//查找下一个与上个元素值不相同的元素
		{
			L.data[++i]=L.data[j];//找到后，则将元素前移
		}
	}
	L.length=i+1;//因为小标是从0开始计数的，所以算长度时需要加上1
}