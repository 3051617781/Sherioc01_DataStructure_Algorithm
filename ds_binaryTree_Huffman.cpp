//哈夫曼树
/*
特点1：不存在1度节点

特点2：若给定权值的叶子节点数为n，则构造的哈夫曼树中的节点数为2n-1
由n(2)= n(0) - 1且哈夫曼树没有1度节点
所以节点总数 = n(0)+n(2) = 2n-1 

特点3：任意一颗哈夫曼树的带权路径长度等于所有 分支节点值 的累加和
*/
#include<iostream>
using namespace std;
//链表结构生成Huffman树，这是最基本的实现方法，但是效率很低；也可以使用堆排序
//实现使用静态链表存储
const int n = 100;
const int m = 2*n-1;
struct HTNode{
    float weight;
    int parent, lchild, rchild;
};
class HuffmanTree{
public:
    HTNode HT[m];
    HuffmanTree();
    ~HuffmanTree();

};
HuffmanTree::HuffmanTree(){
    int i, j;
    for(int i =0; i < m; i++){//初始化静态链表
        HT[i].weight = 0;
        HT[i].parent = -1;
        HT[i].lchild = -1;
        HT[i].rchild = -1;
    }
    for(int i = 0; i < n; i++){
        // select()
    }
}
int main(){

}