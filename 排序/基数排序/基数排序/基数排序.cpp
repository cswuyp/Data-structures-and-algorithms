// 基数排序.cpp: 定义控制台应用程序的入口点。
//
/*基数排序（Radix Sorting）是和前面所述各类排序方法完全不相同的一种排序方法。前述各类
排序方法都是建立在关键字比较的基础上，而基数排序不比较关键的大小，它是根据关键字中各位
的值，通过对排序记录进行若干趟“分配”与“收集”来实现排序，是一种借助多关键字的排序的
思想对单关键字排序的方法
【算法分析】
（1）时间复杂度
对于n个记录（假设每个记录含d个关键字，每个关键字的取值范围为rd个值）进行链式基数排序时
，每一趟分配的时间复杂度为O(n)，每一趟收集的时间复杂度为O(rd),整个排序需进行d趟分配和
收集，所以时间复杂度为O(d(n+rd)).
（2）空间复杂度
所需辅助空间为2rd个队列指针，另外由于需用链表做存储结构，则相对于其他以顺序结构存储记录
的排序方法而言，还增加了n个指针域的空间，所以空间复杂度为O(n+rd)*/
#include "stdafx.h"

#include <iostream>
using namespace std;
#define ArraySize 8


void radix(int data[], int size)
{
	int n;
	for (int i = 1; i <= 100; i = i * 10)
	{
		int tmp[20][10] = { 0 };//建立一个20行，10列的数组，每一列分别代表0~9位数，20行代表能存放的总个数
		for (int j = 0; j<size; j++)
		{
			n = (data[j] / i) % 10;
			tmp[j][n] = data[j];
		}
		int k = 0;
		for (int p = 0; p<10; p++)
			for (int q = 0; q<size; q++)
			{
				if (tmp[q][p] != 0)
					data[k++] = tmp[q][p];
			}
	}


}


int main()
{
	int data[ArraySize];
	/*输入数组数据*/
	cout << "请输入8个数：" << endl;
	for (int i = 0; i<ArraySize; i++)
		cin >> data[i];
	/*执行排序*/
	radix(data, 8);
	/*输出排序结果*/
	cout << "" << endl;
	for (int i = 0; i<ArraySize; i++)
		cout << data[i] << " ";
	return 0;
}

