/*已知在一维数组A[m+n]中依次存放着两个线性表(a1,a2,a3...,am)和(b1,b2,b3...,bn)。
试编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)的前面*/
//解题思路如果不是原地逆置，可以先把两个线性表存入临时创建的两个容器中，然后再从容器中把元素存入线性表中覆盖掉之前的元素
/*算法思想：首先将数组A[m+n]中的全部元素(a1,a2,a3,...,am,b1,b2,b3,...,bn)原地逆置为(bn,bn-1,bn-2...b1,am,am-1,am-2,...a1)
再对前n个元素和后m个元素分别使用逆置算法，就可以得到(b1,b2,b3,...,bn,a1,a2,a3,...am),
从而实现顺序表的位置互换*/
void Reverse(int A[],int left,int right,int arraysize)
{
	if(left>=right||right>=arraysize)
	{
		return;
	}
	int mid=(left+right)/2;//不考虑线性表中两个小线性表的存储情况，直接把整个表逆置，需要操作的次数是整个表长度的一半
	for(int i=0;i<=mid-left;i++)//操作次数是进行操作的表的长度的一半
	{
		int temp=A[left+i];
		A[left+i]=A[right-i];
		A[right-i]=temp;
	}
}
void Exchange(int A[],int m,int n,int arraysize)
{
	Reverse(A,0,m+n-1,arraysize);
	Reverse(A,0,n-1,arraysize);
	Reverse(A,n,m+n-1,arraysize);
}