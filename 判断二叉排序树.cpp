#include "stdio.h"
#include "stdlib.h"
typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}Bitree;
Bitree *B[100];
Bitree *CreateBiTree()
{
	int num,i,n;
	Bitree *t,*s;
	t=NULL;
	printf("建立二叉树（1表示为虚结点，0表示输入结束）：/n");
	num=0;
	scanf("%d",&n);
	while(n!=0)
	{
		s=(Bitree *)malloc(sizeof(Bitree));
		s->data=n;
		s->lchild=s->rchild=NULL;
		num++;
		if(!t)
			t=s;
		B[num]=s;
		scanf("%d",&n);
	}
	for(i=1;i<=num;i++)
	{
		if(B[i]->data!=1)
		{
			if(2*i<=num && B[2*i]->data!=1)
				B[i]->lchild=B[2*i];
			if(2*i+1<=num && B[2*i+1]->data!=1)
				B[i]->rchild=B[2*i+1];
		}
	}
	return t;
}
int IsSearchTree(const Bitree *t)  //递归遍历二叉树是否为二叉排序树
{
	if(!t)        //空二叉树情况(空树也是二叉排序树)
		return 1;
	else if(!(t->lchild) && !(t->rchild))   //左右子树都无情况(只有根结点也是二叉排序树)到最后叶子结点的左右子树都为空所以也会返回1
		return 1;
	else if((t->lchild) && !(t->rchild))    //只有左子树情况
	{
		if(t->lchild->data>t->data)
			return 0;
		else
			return IsSearchTree(t->lchild);
	}
	else if((t->rchild) && !(t->lchild))   //只有右子树情况
	{
		if(t->rchild->data<t->data)
			return 0;
		else
			return IsSearchTree(t->rchild);
	}
	else         //左右子树全有情况
	{                                
		if((t->lchild->data>t->data) || (t->rchild->data<t->data))
			return 0;
		else
			return ( IsSearchTree(t->lchild) && IsSearchTree(t->rchild) );
	}
}
int main(void)
{
	int flag=0;
	Bitree *tree;
	tree=CreateBiTree();
	flag=IsSearchTree(tree);
	if(flag)
		printf("这棵树是二叉排序树！/n");
	else
		printf("这棵树不是二叉排序树！/n");
	system("pause");
	return 0;
}