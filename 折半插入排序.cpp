/*折半插入排序*/
#include<stdio.h>
void print(int a[],int n,int i)
{
	printf("%d:",i);
	for(int j=0;j<n;j++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
void BInsertSort(int a[],int size)
{
	int i,j,low=0,high=0,mid;
	int temp=0;
	for(i=1;i<size;i++)
	{
		low=0;
		high=i-1;
		temp=a[i];//待插入的数据
		//采用折半查找法判断插入位置，最终变量low表示插入位置
		while(low<=high)
		{
			mid=(low+high)/2;
			if(a[mid]>temp)
			{
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		//有序表中插入位置后的元素统一后移
		for(j=i;j>low;j--)
		{
			a[j]=a[j-1];
		}
		a[low]=temp;//插入元素
		print(a,8,i);
	}
}
int main()
{
	int a[8]={2,3,5,6,8,7,5,4};
	BInsertSort(a,8);
	return 0;
}