#include<iostream>
using namespace std;

//定义节点
typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    char data;
}BiTreeNode, *BiTree; 　　　 //*BiTree的意思是给 struct node*起了个别名，叫BiTree，故BiTree为指向节点的指针。


//按照前序顺序建立二叉树
void createBiTree(BiTree &T) //&的意思是传进来节点指针的引用，括号内等价于 BiTreeNode* &T,目的是让传递进来的指针发生改变
{               　　　　　　　　 
    char c;
    cin >> c;
    if('#' == c)             //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
        T = NULL;
    else
    {
        T = new BiTreeNode;
        T->data=c;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
}

//前序遍历二叉树并打印
void preTraverse(BiTree T)
{
    if(T)
    {
        cout<<T->data<<" ";
        preTraverse(T->lchild);
        preTraverse(T->rchild);
    }
}
//中序遍历二叉树并打印
void midTraverse(BiTree T)
{
    if(T)
    {
        midTraverse(T->lchild);
        cout<<T->data<<" ";
        midTraverse(T->rchild);
    }
}
//后续遍历二叉树并打印
void postTraverse(BiTree T)
{
    if(T)
    {
        postTraverse(T->lchild);
        postTraverse(T->rchild);
        cout<<T->data<<" ";
    }
}
int main()
{
    BiTree T;               //声明一个指向二叉树根节点的指针               
    createBiTree(T);
    cout<<"二叉树创建完成！"<<endl;
    cout<<"前序遍历二叉树："<<endl;
    preTraverse(T);
    cout<<endl;
    cout<<"中序遍历二叉树："<<endl;
    midTraverse(T);
    cout<<endl;
    cout<<"后序遍历二叉树："<<endl;
    postTraverse(T);
    return 0;
}