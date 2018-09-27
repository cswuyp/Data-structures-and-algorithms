/**/
status InitList(SqList &L)
{
	L.elem=new ElemType[MAXSIZE];//为顺序表分配一个大小为MAXSIZE的数组空间
	if(!L.elem)//分配失败
		return false;
	L.length=0;//表的当前长度为0
	return true;
}