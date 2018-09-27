/*顺序查找，又称为线性查找，主要用于线性表中进行查找。顺序查找通常分为对一般的无序线性表
的顺序查找和对按关键字有序的顺序表的顺序查找。*/
/*typedef struct//查找表的数据结构
{
	ElemType *elem;//元素存储空间的基址，建表时按实际长度分配，0号单元留空
	int TableLen;//表的长度
}SSTable;
int Search_Seq(SSTable ST,ElemType key)
{//在顺序表ST中顺序查找关键字为key的元素。若找到则返回该元素在表中的位置
	ST.elem[0]=key;//“哨兵”
	for(i=ST.TableLen;ST.elem[i]!=key;--i);//从后往前找
	return i;//若表中不存在关键字为key的元素，将查找到i为0时推出for循环
}*/
#include<stdio.h>
#include<stdlib.h>
#define keyType int
typedef struct
{
	keyType key;//查找表中每个数据元素的值
	//如果需要可以添加其他属性
}ElemType;

typedef struct
{
	ElemType *elem;//存放查找表中数据元素的数组
	int length;//记录查找表中数据的总数量
}SSTable；
//创建查找表
void Create(SSTable **st,int length)
{
	(*st)=(SSTable*)malloc(sizeof(SSTable));
	(*st)->length=length;
	printf("输入表中的数据元素:\n");
	//根据查找表中数据元素的总长度，在存储时，从数组下标为1的空间开始存储数据
	for(int i=1;i<=length;i++)
	{
		scanf("%d",&((*st)->elem[i].key));//这里存入线性表时下标是从1开始的所以下面才可以把下标为0作为监视哨
	}
}
//查找表查找的功能函数，其中key为关键字
int Search_Seq(SSTable *st,keyType key)
{
	st->elem[0].key=key;//将关键字作为一个数据元素存放到查找表的第一个位置，起监事哨的作用
	int i=st->length;
	//从查找的最后一个数据元素依次遍历，一直遍历到数组下标为0
	while(st->elem[i].key!=key)
	{
		i--;
	}
	//如果i=0，说明查找失败，反之，返回的是含有关键字key的数据元素在查找表中的位置
	return i;
}
int main(int argc,const char*argv[])
{
	SSTable *st;
	Create(&st,6);
	getchar();
	printf("请输入查找数据的关键字:\n");
	int key;
	scanf("%d",&key);
	int location=Search_Seq(st,key);
	if(location==0)
	{
		printf("查找失败");
	}
	else
	{
		printf("数据在查找表中的位置为:%d",location);
	}
	return 0;
}
