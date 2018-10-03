class Solution {
public:
    int StrToInt(string str) 
    {
        int length=str.length();//先计算字符串的长度
        if(length==0)
        {
            return 0;
        }
        int result=0;
        int flag=1;
        int i=0;
        if(str[i]=='-')
        {
            flag=-1;
            i++;
        }
        if(str[i]=='+')
        {
            flag=1;
            i++;
        }
        
        while(str[i]!='\0')
        {
            if(str[i]==' ')//删掉数字前面的空格
            {
                i++;
            }
            if(str[i]>='0'&&str[i]<='9')
            {
                result=(result*10+flag*(str[i]-'0'));
                i++;
            }
            else
            {
                return 0;
            }
        }
        return result;
    }
};