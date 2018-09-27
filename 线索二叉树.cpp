/*递归中序线索化二叉树*/

#include <iostream>
#include <malloc.h>
using namespace std;
#define TElemType char

typedef enum{Link, Thread} PointerTag;
//线索存储标志位
//Link(0):表示指向左右孩子的指针
//Thread(1):表示指向前驱或后继的线索

typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag ltag, rtag;
}BiThrNode;

void CreatBiThreadTree(BiThrNode *&T)
{
    char e;
    cin>>e;
    if(e == '#') T = NULL;
    else{
        T = (BiThrNode *) malloc (sizeof(BiThrNode));
        T->data = e;
        T->ltag = T->ltag = Link;
        CreatBiThreadTree(T->lchild);
        CreatBiThreadTree(T->rchild);
    }
}

void InOrderTraverse(BiThrNode *T)
{
    if(T){
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}

//中序递归线索化算法
void InThreading(BiThrNode *&T,BiThrNode *&pre)
{
    if(T){
        InThreading(T->lchild, pre);    //递归左孩子线索化 
        if(!T->lchild){
            T->ltag = Thread;
            T->lchild = pre;
        }
        if(!pre->rchild){
            pre->rtag = Thread;
            pre->rchild = T;
        }
        pre = T;
        InThreading(T->rchild, pre);    //递归右孩子线索化 
    }
}

BiThrNode *InOrderThrTree(BiThrNode *T)
{
    BiThrNode *Thre, *pre;
    Thre = (BiThrNode *) malloc (sizeof(BiThrNode));    //创建一个结点，左指针指向二叉树根结点，右结点指向自身
    Thre->lchild = T;
    Thre->rchild = Thre;
    pre = Thre;
    InThreading(T, pre);    //中序递归线索化
    pre->rtag = Thread;
    pre->rchild = Thre;
    Thre->rchild = pre;
    return Thre;
}

void InOrderThreading(BiThrNode *Thre)
{
    BiThrNode *p;
    p = Thre->lchild;
    while(p != Thre)
	{   //指针p指回Thre时，遍历结束
        while(p->ltag == Link) p = p->lchild;   //左标志位为指针，则向左走
        cout<<p->data;
        while(p->rtag == Thread && p->rchild != Thre)
		{  //右标志位为线索，并且右孩子不指回Thre，访问p结点后继一次并输出一次
            p = p->rchild;
            cout<<p->data;
        }
        p = p->rchild;  //左孩子为空，右线索为指针，则向右移动一次
    }
    cout<<endl;
}

int main()
{
    BiThrNode *t = NULL;
    BiThrNode *thre;
    CreatBiThreadTree(t);
    cout<<"中序遍历：";
    InOrderTraverse(t);
    cout<<"\n线索化中序遍历：";
    thre = InOrderThrTree(t);
    InOrderThreading(thre);
    return 0;
}