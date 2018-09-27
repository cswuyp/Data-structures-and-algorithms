/*设计一个高效的算法，将顺序表的所有元素逆置，要求算法的空间复杂度为O(1)*/
/*算法思想：扫描顺序表L的前半部分元素，对于元素L.data[i](0<=i<=L.length/2),
将其余后半部分对应的元素L.data[L.length-i-1]进行交换*/
//其实这个算法也相当于把第一个元素和最后一个元素进行交换接着是第二个元素和倒数第二个元素进行交换，最后到了中间的两个元素
//交换完之后我们会发现整个表都逆置了，此时进行的交换次数正好为表长度的一半
void Reverse(Sqlite &L)
{
	ElemType temp;
	for(int i=0;i<L.length/2;i++)
	{
		temp=L.data[i];
		L.data[i]=L.data[L.length-i-1]
		L.data[L.length-i-1]=temp;
	}
}