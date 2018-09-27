class Solution
{
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV) 
	{
		if(pushV.size==0)
			return false;
	}
	vector<int>stack;//做一个临时（辅助）容器
	for(int i=0,j=0;i<pushV.size();)
	{
		stack.push_back(pushV[i++]);
		while(j<popV.size()&&stack.back()==popV[j])//如果容器最后一个元素等于popV[j]则进入循环
		{
			stack.pop_back();//移除容器中的最后一个元素
			j++;
		}
	}
	return stack.empty();//此时如果容器中元素为空则返回的值是true，容器中元素不为空则返回的值是false
}