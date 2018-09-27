/*函数调用时，将实际参数传递给形参表可以有两种形式：赋值调用，引用调用，
“赋值调用”形式是将参数的值传递给函数的形参表。此时函数中形参的值发生变化，不会影响函数调用时使用的变量（实际参数）。
“引用调用”形式是将实际参数的地址复制给形式参数。当函数调用时，这个地址用来访问所使用的实际参数。
这意味着在函数调用过程中，形参的数值变化会直接反映到实际参数的值。*/
#include<iostream>
#include<cmath>
using namespace std;
double pow2(float x);//声明
double pow3(float x);//声明
double pow2(float)//定义
{
	double z=0;
	z=x*x;
	return z;
} 
double pow3(float*y)
{
	double z=0;
	z=(*y)*(*y)*(*y);
	return z;
}
void main()
{
	double A=10;
	float B=20;
	double C=0;
	double D=0;
	C=pow2(A);
	cout<<"A:"<<A<<" ;pow2(A): "<<C<<endl;
	D=pow3(&B);
	cout<<"B:"<<B<<" ;pow(&B): "<<D<<endl;
	cin.get();
}