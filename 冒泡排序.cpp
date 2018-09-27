/*冒泡排序*/
#include<stdio.h>
//交换a和b的位置函数
void swap(int *a,int *b);
int main()
{
	int array[8]={49,38,65,97,76,13,27,49};
	int i,j;
	int key;
	//有多少记录，就需要多少次冒泡，相比较过程，所有记录都按照升序排列时，排序结束
	for(i=0;i<8;i++)
	{
		key=0;//每次开始冒泡前，初始化key值为0
		//每次起泡下标为0开始，到8-i结束
		for(j=0;j+1<8-i;j++)
		{
			if(array[j]>arra[j+1])
			{
				key=1;
				swap(&array[j],&array[j+1]);
			}
		}
		//如果key值为0，表明表中记录排序完成
		if(key==0)
		{
			break;
		}
	}
	for(i=0;i<8;i++)
		{
			printf("%d",array[i]);
		}
		return 0;
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}













