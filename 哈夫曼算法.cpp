#include <iostream>
#include <iomanip>
using namespace std;

//哈夫曼树的存储表示
typedef struct
{
    int weight;    // 权值
    int parent, lChild, rChild;    // 双亲及左右孩子的下标 
}HTNode, *HuffmanTree;


// 选择权值最小的两颗树 
void SelectMin(HuffmanTree hT, int n, int &s1, int &s2)
{
    s1 = s2 = 0;

    int i;
    for(i = 1; i < n; ++ i){
        if(0 == hT[i].parent){
            if(0 == s1){
                s1 = i;
            }
            else{
                s2 = i;
                break;
            }
        }
    }
    if(hT[s1].weight > hT[s2].weight){
        int t = s1;
        s1 = s2;
        s2 = t;
    }

    for(i += 1; i < n; ++ i){
        if(0 == hT[i].parent){
            if(hT[i].weight < hT[s1].weight){
                s2 = s1;
                s1 = i;
            }else if(hT[i].weight < hT[s2].weight){
                s2 = i;
            }
        }
    }
}

// 构造有n个权值（叶子节点）的哈夫曼树 
void CreateHufmanTree(HuffmanTree &hT)
{
    int n, m;
    cin >> n;
    m = 2*n - 1;

    hT = new HTNode[m + 1];    // 0号节点不使用 
    for(int i = 1; i <= m; ++ i){
        hT[i].parent = hT[i].lChild = hT[i].rChild = 0;
    }
    for(int i = 1; i <= n; ++ i){
        cin >> hT[i].weight;    // 输入权值 
    }
    hT[0].weight = m;    // 用0号节点保存节点数量 

    /****** 初始化完毕, 创建哈夫曼树 ******/
    for(int i = n + 1; i <= m; ++ i){
        int s1, s2;
        SelectMin(hT, i, s1, s2);

        hT[s1].parent = hT[s2].parent = i;
        hT[i].lChild = s1; hT[i].rChild = s2;    // 作为新节点的孩子 
        hT[i].weight = hT[s1].weight + hT[s2].weight;    // 新节点为左右孩子节点权值之和 
    }
}

int HuffmanTreeWPL_(HuffmanTree hT, int i, int deepth)
{
    if(hT[i].lChild == 0 && hT[i].rChild == 0){
        return hT[i].weight * deepth;
    }
    else{
        return HuffmanTreeWPL_(hT, hT[i].lChild, deepth + 1) + HuffmanTreeWPL_(hT, hT[i].rChild, deepth + 1);
    }
}

// 计算WPL（带权路径长度） 
int HuffmanTreeWPL(HuffmanTree hT)
{
    return HuffmanTreeWPL_(hT, hT[0].weight, 0);
}

// 输出哈夫曼树各节点的状态 
void Print(HuffmanTree hT)
{
    cout << "index weight parent lChild rChild" << endl;
    cout << left;    // 左对齐输出 
    for(int i = 1, m = hT[0].weight; i <= m; ++ i){
        cout << setw(5) << i << " ";
        cout << setw(6) << hT[i].weight << " ";
        cout << setw(6) << hT[i].parent << " ";
        cout << setw(6) << hT[i].lChild << " ";
        cout << setw(6) << hT[i].rChild << endl;
    }
}

// 销毁哈夫曼树 
void DestoryHuffmanTree(HuffmanTree &hT)
{
    delete[] hT;
    hT = NULL;
}

int main()
{
    HuffmanTree hT;
    CreateHufmanTree(hT);
    Print(hT); 
    cout << "WPL = " << HuffmanTreeWPL(hT) << endl;
    DestoryHuffmanTree(hT);
    return 0;
}