#include "stdafx.h"
#include  <iostream>
#include <stack>
using namespace std;

void printArray(int *a, int n)
{
	for (int i = 0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void  Merge(int * a, int low, int mid, int high)
{
	int i = low, j = mid + 1, p = 0;
	int * r = new int[high - low + 1];
	while (i <= mid && j <= high)
	{
		r[p++] = (a[i] <= a[j]) ? a[i++] : a[j++];
	}
	while (i <= mid)
		r[p++] = a[i++];
	while (j <= high)
		r[p++] = a[j++];
	for (p = 0, i = low; i <= high; p++, i++)
		a[i] = r[p];
	delete[] r;
}

/*
void MergePass(int *a,int n,int length)
{
int i=0;
for(;i+2*length<n-1;i+=2*length)
{
Merge(a,i,i+length-1,i+2*length-1);
}
if(i+length<=n-1)
Merge(a,i,i+length-1,n-1);//尚有两个子文件，其中后一个长度小于length,归并最后两个子文件
//注意：若i≤n-1且i+length-1≥n-1时，则剩余一个子文件轮空，无须归并
}
//自底向上
void MergeSort(int *a,int n)
{
for(int length=1;length<n;length*=2)
MergePass(a,n,length);
}
*/

//自顶向下(递归实现)
void MSort(int *a, int low, int high)
{
	if (low<high)
	{
		int mid = (low + high) / 2;
		MSort(a, low, mid);
		MSort(a, mid + 1, high);
		Merge(a, low, mid, high);
	}
}

void MergeSort(int *a, int n)
{
	MSort(a, 0, n - 1);
}

//将上述递归转化为非递归
#define Partition '0' //划分
#define Mergetion '1' //归并
typedef struct Region
{
	int first;//起始位置
	int end;  //结束位置
	char flag;//标记该区域是应该划分还是应该归并  
}Region;
//非递归实现(感觉跟二叉树后序遍历的非递归实现很像)
void  NonRecursiveMergeSort(int *a, int len)
{
	stack<Region> region_stack;
	Region beginRegion;
	beginRegion.first = 0;
	beginRegion.end = len - 1;
	beginRegion.flag = Partition;
	region_stack.push(beginRegion);
	while (!region_stack.empty())
	{
		Region region = region_stack.top();
		region_stack.pop();//从栈中删除
		if (region.flag == Mergetion)//应该归并
		{
			Merge(a, region.first, (region.first + region.end) / 2, region.end);//归并之
		}
		else //应该划分
		{
			if (region.first + 1 >= region.end)//如果区域是两个相邻的数
			{
				Merge(a, region.first, (region.first + region.end) / 2, region.end);//直接合并之
			}
			else //否则应该划分
			{
				region.flag = Mergetion;//下次应该归并
				region_stack.push(region);
				int mid = (region.first + region.end) / 2;

				Region region_low;
				region_low.first = region.first;
				region_low.end = mid;
				region_low.flag = Partition;
				region_stack.push(region_low);

				Region region_up;
				region_up.first = mid + 1;
				region_up.end = region.end;
				region_up.flag = Partition;
				region_stack.push(region_up);
			}
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 49,38,65,97,76,13,27,49 };
	int n = sizeof(a) / sizeof(int);
	printArray(a, n);
	MergeSort(a,n);
	//NonRecursiveMergeSort(a, n);
	printArray(a, n);
	system("PAUSE");
	return 0;
}
