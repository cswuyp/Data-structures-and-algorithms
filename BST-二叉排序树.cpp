#include<iostream>
using namespace std;
//定义节点
typedef struct BiNode
{
    int data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

//插入函数
void insertBST(BiTree &T,int key)
{
    if(NULL==T)
    {
        T=new BiNode;
        T->data=key;
        T->lchild=T->rchild=NULL;
    }
    else if(T->data==key)
        cout<<"不能重复！";
    else if(T->data>key)
        insertBST(T->lchild,key);
    else
        insertBST(T->rchild,key);

}
//通过插入函数实现创建二叉排序树
void createBST(BiTree &T)
{
    int n;
    cout<<"请输入要插入的节点数： ";
    cin>>n;
    int a[n];
    cout<<"请输入要插入的数据：中间用空格分开"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        insertBST(T,a[i]);
    }

    cout<<"创建二叉排序树完成！"<<endl;

}

//前序遍历并打印
void preOrderTraverse(BiTree T)
{
    if(T)
    {
        cout <<T->data<< " ";
        preOrderTraverse(T->lchild);
        preOrderTraverse(T->rchild);
    }
}
//中序遍历并打印
void midOrderTraverse(BiTree T)
{

    if(T)
    {
        midOrderTraverse(T->lchild);
        cout <<T->data<< " ";
        midOrderTraverse(T->rchild);
    }
}

//定义全局变量layer，表示层数
int layer=0;
//下面是查找函数，返回是否查找到数据并且可以确定查找元素的层数
bool searchBST(BiTree &T,int key)
{
    layer++;
    if(T==NULL)
    {
        return false;
    }
    else
    {
        if (key==T->data)
        {

            return true;

        }
        else if(key<T->data)
            searchBST(T->lchild,key);
        else
            searchBST(T->rchild,key);
    }
}
//利用上面查找函数实现查找操作
void findBST(BiTree &T)
{
    int k;
    cout<<"请输入要查找的元素值： ";
    cin>>k;
    if(searchBST(T,k))
    {
        cout<<"查找成功，该元素位于二叉树中！"<<endl;
        cout<<"层数为："<<layer<<endl;
    }

    else
        cout<<"没有查找到该元素！"<<endl;
}
　　　 　//定义删除节点的函数
void deletenode(BiTree &p)
{
    BiTree q,s;           //函数形参P指向要删除的节点，即它的双亲节点的rchild
    //根据要删除的节点的孩子情况分三种讨论
    //没有左孩子
    if(!p->lchild)
    {
       q=p;
       p=p->rchild;
       delete q;
    }
    //没有右孩子
    if(!p->rchild)
    {
        q=p;
        p=p->lchild;
        delete q;

    }
    //两个孩子都有
    else
    {
        q=p;                //q指向上一个节点，s指向下一个节点，即指向q的右孩子，初始时q=p,最终s指向跟p节点换值的那个节点。
        s=q->lchild;

    while(s->rchild)　　　　//通过这个循环实现寻找最接近要删除节点（p）值的节点
    {
        q=s;
        s=s->rchild;
    }
    p->data=s->data;　　　　//交换值，有个注意事项，s是不存在右孩子的，因为如果存在，则右孩子比他大，更接近p，s需要继续循环，最终s还是没有右孩子。
    if(q!=p)　　　　　　　　　　
    {
        q->rchild=s->lchild;
    }
    else　　　　　　　　//如果q,s 没有移动，即此时q=p,s的初始值就是最接近p点的节点，此时q不存在右节点，需要单独讨论
    {
        q->lchild=s->lchild;　　　　　　
    }
    delete s;
    }


}

//删除操作
bool deleteBST(BiTree &T,int del)
{
    if(!T)
        return false;
    else
    {
            if(T->data==del)
        {
             deletenode(T);
             return true;
        }
        else if(del<T->data)
        {
            return deleteBST(T->lchild,del);
        }
        else
        {
            return deleteBST(T->rchild,del);
        }
    }

}
//主函数
int main()
{
    BiTree T=NULL;
    int d;
    createBST(T);
    cout<<"前序遍历的结果为："<<endl;
    preOrderTraverse(T);
    cout<<endl;
    cout<<"中序遍历的结果为："<<endl;
    midOrderTraverse(T);
    cout<<endl;
    findBST(T);
    cout<<"请输入要删除的数据："<<endl;
    cin>>d;
    deleteBST(T,d);
    cout<<"前序遍历的结果为："<<endl;
    preOrderTraverse(T);

}