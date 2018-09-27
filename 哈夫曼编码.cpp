#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//哈夫曼树的存储表示
typedef struct
{
    int weight;    // 权值
    int parent, lChild, rChild;    // 双亲及左右孩子的下标 
}HTNode, *HuffmanTree;

// 哈夫曼编码表的存储表示
typedef struct
{
    char** code;    // 编码表 
    int n;          // 编码数 
}HuffmanCode;

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

// 构造根据哈夫曼树来哈夫曼编码 
void CreateHuffmanCode(HuffmanTree hT, HuffmanCode &hC)
{
    hC.n = (hT[0].weight + 1)/2;
    hC.code = new char*[hC.n + 1];    // 0位置不使用 

    char *cd = new char[hC.n];  // 临时存放每个编码 

    for(int i = 1; i <= hC.n; ++ i){

        // 每次从叶子节点向上回溯构造编码 
        int len = 0, child = i, parent = hT[i].parent;
        while(parent != 0){
            if(hT[parent].lChild == child){
                cd[len ++] = '0';
            }
            else{
                cd[len ++] = '1';
            }
            child = parent;
            parent = hT[parent].parent;
        }
        cd[len] = 0;

        reverse(cd, cd + len);    // 将序列翻转 
        hC.code[i] = new char[len];
        strcpy(hC.code[i], cd);
    }
    delete[] cd;
}

// 输出哈夫曼表 
void PrintHuffmanCode(HuffmanCode &hC)
{
    for(int i = 1; i <= hC.n; ++ i){
        cout << hC.code[i] << endl;
    }
}

// 销毁哈夫曼树 
void DestoryHuffmanTree(HuffmanTree &hT)
{
    delete[] hT;
    hT = NULL;
}

// 销毁哈夫曼编码表
void DestoryHuffmanCode(HuffmanCode &hC)
{
    for(int i = 1; i <= hC.n; ++ i){
        delete[] hC.code[i];
    }
    delete[] hC.code;
    hC.code = NULL;
}

int main()
{
    HuffmanTree hT;
    CreateHufmanTree(hT);

    HuffmanCode hC;
    CreateHuffmanCode(hT, hC);
    PrintHuffmanCode(hC);

    DestoryHuffmanTree(hT);
    DestoryHuffmanCode(hC);
    return 0;
}