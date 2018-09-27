/*实现两个大整数相加，因为用int和long都不能满足（溢出）*/
#include <iostream>
#include <cstring>
#include <stack>
#include<string>
using namespace std;
 
int isnum(string str)
{
for (int i = 0; i < str.size(); i++)
{
    if (!isdigit(str[i])) //判断是否有非数字的元素
    {
        cout<<"error"<<endl;
        return 0;
    }
}
    return 1;
}
 
int main()
{
	string a,b;
	while (cin >> a >> b)
	{
		int sum = 0;
		int n = a.length()-1;
		int m = b.length()-1;
		stack<int> istack;
		int flag = 0;
		if (isnum(a) && isnum(b))
		{
			while (m >= 0 && n >= 0)
			{
				sum = (a[n--] - '0') + (b[m--] - '0') + flag;//字符串从后往前相加，跟正常的加法计算一样，flag存放的低位的进位数
				flag = sum / 10;//做进位处理，如果两个数相加超过10就把十位的数字存在flag
				istack.push(sum % 10);//把结果的个位数存入栈中
			}
			if (n >= 0)//如果字符串b结束字符串a还未结束
			{
				sum = (a[n--] - '0') + flag;
				flag = sum / 10;
				istack.push(sum % 10);
			}
			if (m >= 0)//如果字符串a结束字符串b还未结束
			{
				sum = (b[m--] - '0') + flag;
				flag = sum / 10;
				istack.push(sum % 10);
			}
			if (m < 0 && n < 0&&flag>0)
			{
				istack.push(flag);
			}
			while (!istack.empty())
			{
				cout << istack.top();
				istack.pop();
			}
			cout << endl;
		}
	}
	return 0;
}
