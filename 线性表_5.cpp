/*从顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素，如果s或t不合理或者顺序表为空则显示出错误信息并退出运行*/
bool ListDelete(SqList &L,int s,int t)//注意这里只是一个顺序表但不是有序的，所以需要遍历整个表进行比较元素大小
{
	if(s>=t||L.length==0)
	{
		return false;//线性表为空或s，t不合法，返回
	}
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]>=s&&L.data[i]<=t)
		{
			k++;
		}
		else
		{
			L.data[i-k]=L.data[i];//当前元素前移k个位置
		}
	}
	L.length-=k;//长度减小
	return true;
}