/*折半查找，也称二分查找，在某些情况下相比于顺序查找，使用折半查找算法的效率更高。
但是该算法的使用前提是静态查找表中的是数据必须是有序的*/

#include<stdio.h>
#Include<stdlib.h>
#define keyType int
typedef struct
{
	keyType key;//查找表中每个数据元素的值
	//如果需要，还可以添加其他属性
}ElemType;

typedef struct
{
	ElemType *elem;//存放查找表中数据元素的数组
	int length;//记录查找中数据的总数量
}SSTable;

//创建查找表
void Create(SSTable **st,int length)
{
	(*st)=(SSTable*)malloc(sizeof(SSTable));//申请内存空间
	(*st)->length=length;//给表的长度赋值
	printf("输入表中数据元素:\n");
	//根据查找表中数据元素的总长度，在存储时，从数组下标为1的空间开始存储数据
	for(int i=1;i<=length;i++)
	{
		scanf("%d",&((*st)->elem[i].key));
	}
}

//折半查找算法
int Search_Bin(SSTable *ST,keyType key)
{
	int low=1;//初始状态low指针指向第一个关键字
	int high=ST->length;//high指向最后一个关键字
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(ST->elem[mid].key==key)//如果mid指向的同要查找的相等，返回mid所指向的位置
		{
			return mid;
		}
		else if(ST->elem[mid].key>key)//如果mid指向的关键字较大，则更新high指针的位置
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return 0;
}

int main()
{
	SSTable *st;
	Create(&st,11);
	getchar();
	printf("请输入查找数据的关键字:\n");
	int key;
	scanf("%d",&key);
	int location=Search_Bin(st,key);
	if(location==0)
	{
		printf("查找表中午该元素");
	}
	else
	{
		printf("数据在查找表中的位置为:%d",location);
	}
	return 0;
}