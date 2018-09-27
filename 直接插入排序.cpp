/*直接插入排序*/
#include<stdio.h>
//自定义的输出函数
void print(int a[],int n,int i)
{
	printf("%d",i);
	for(int j=0;j<n;j++)
	{
		printf("%d",a[j]);
	}
	printf("\n");
}
//直接插入排序*/
void InsertSort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i-1])//若第i个元素大于i-1元素则直接插入(因为在同一个数组中进行操作，所以不需要做任何操作直接跳过就可以了)；反之，需要找到适当的插入位置后再插入
		{
			int j=i-1;
			int x=a[i];
			while(j>=0&&x<a[j])
			{
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=x;//插入到正确的位置
		}
		printf(a,n,i);//打印每次排序后的结果
	}
}
int main()
{
	int a[8]={3,1,7,5,2,4,9,6};
	InsertSort(a,8);
	return 0;
}