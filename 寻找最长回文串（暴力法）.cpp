/*算法思想：暴力法即不做记录
第一，定义一个pStr指向字符串str，再定义一个p指向pStr，q指向pStr+1；
第二，找出一个字符*p与其下一个字符*q相同位置，比如oo，num++，index = p；然后比较
这两个相同字符*p,*q两边的字符是否相等，如果相等再向两边扩展p--,q++(p>str&&q!='\0')。如果p指向首部，即p=str,则调出while循环，再比较一次if(*p == *q),num++,index = q.
第三，如果发现连续两个字符不相等，则让pStr++,p=pStr,q =pStr+1.
第四，通过maxNum和maxIndex记录下最长回文的数目和位置。*/
#include <iostream>
using namespace std;

void GetLongestSymmetricalLength(char* str)
{
    if(str==NULL)
        return;

    char* pStr = str;
    char* p = pStr;
    char* q = pStr+1; 
    int num=0;
    int maxNum=0;;
    char* index = pStr;
    char* maxIndex = index;

    while(*pStr != '\0')
    {
        while((*p != *q))
        {
            num = 0;
            pStr++;
            p = pStr;
            q = pStr+1;
        }
        while((*p == *q)&&(p > str)&&(*q != '\0'))
        {
            num++;
            index = p;
            p--;
            q++;
        }
        if((p == str)&&(*p == *q)&&(*q != '\0'))
        {
            num++;
            index = p;
        }

        if(num > maxNum)
        {
            maxNum = num;
            maxIndex = index;
        }

        pStr++;
        p = pStr;
        q = pStr+1;
    }
    cout << "Result: " ;
    for(int i=0;i<2*maxNum;++i)
        cout << *maxIndex++ << " ";
    cout << endl;
    cout << "maxNum: "  << maxNum << endl;
}

int main()
{
    char* str = "abbacaacab";
    GetLongestSymmetricalLength(str);

    return 0;
}