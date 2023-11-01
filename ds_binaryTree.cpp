//二叉树
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
typedef int DataType;
class BTNode{
public:
    DataType data;
    BTNode * leftChild, * rightChild;
    BTNode(){leftChild = nullptr; rightChild = nullptr;}
};
class BTree{
public:
    BTNode* root;
    BTree(){root = nullptr;}
    ~BTree(){DeleteTree();}
    bool InsertLeft(BTNode * current, DataType x);
    bool InsertRight(BTNode* current, DataType x);
    void Preorder(BTNode  *current);       //先序遍历
    void InOrder(BTNode *current);        //中序遍历
    void Postorder(BTNode *current);      //后序遍历
    void LevelOrder(BTNode* current);   //层次遍历
    int Count(BTNode* current );//计算二叉树的节点数
    int Height(BTNode* current);//计算二叉树的高度
    BTNode * Find(BTNode *current, DataType x);
                                            //搜索值为x的结点
    void Destroy(BTNode * current);       //删除指定子树
    void DeleteTree(){Destroy(root); root = nullptr; }//删除整棵树
    bool IsEmpty( ){ return root == nullptr;}     //判树空否
    BTNode * CreatBTree() ;              //创建一棵二叉树
};
bool BTree::InsertLeft(BTNode* current, DataType x){
    if(current == nullptr)return false;
    BTNode* p = new BTNode;
    p->data = x;
    current->leftChild = p ;
    return true;
}
bool BTree::InsertRight(BTNode* current, DataType x){
    if(current == nullptr)return false;
    BTNode* p = new BTNode;
    p->data = x;
    current->rightChild = p;
    return true;
}
void BTree::Destroy(BTNode* current){
    if(current != nullptr){
        Destroy(current->leftChild);
        Destroy(current->rightChild);
        delete current;
    }
}
BTNode * BTree::Find(BTNode* current, DataType x){
    if(current == nullptr)return nullptr;
    if(current->data == x)return current;
    BTNode* p = Find(current->leftChild, x);
    if(p != nullptr)return p;
    else return Find(current->rightChild, x);
}
BTNode * BTree::CreatBTree(){//先序输入构造二叉树
    DataType x;
    cin>>x;
    BTNode *T;
    if(x == 0){
        T = nullptr;
    }else{
        T = new BTNode;
        T->data = x;
        T->leftChild = CreatBTree();
        T->rightChild = CreatBTree();
    }
    return T;
}
//遍历二叉树
//先序遍历（递归实现）
void BTree::Preorder(BTNode* current){
    if(current != nullptr){
        cout << current->data;
        Preorder(current->leftChild);
        Preorder(current->rightChild);
    }
}
//先序遍历（栈实现）
/*顺着二叉树节点从左孩子可以一直往下访问，如何访问各个节点的右孩子？
需要将访问过的节点记录下来，后记录的节点先处理，故用栈*/
void BTree:: Preorder(BTNode* p){
    stack<BTNode*> s;
    while(p || !s.empty()){
        if(p){
            cout<< p->data<<endl;
            s.push(p);
            p = p->leftChild;
        }else{//递归到了叶子
            p = s.top()->rightChild;//取父亲的右孩
            s.pop();
        }
    }
}

//中序遍历(递归实现)
void BTree::InOrder(BTNode* current){
    if(current != nullptr){
        InOrder(current->leftChild);
        cout<< current->data;
        InOrder(current->rightChild);
    }
}
//中序遍历（栈实现）
void BTree::InOrder(BTNode* p){
    stack<BTNode*> s;
    while(p || s.empty()){
        if(p->leftChild){
            s.push(p);
            p = p->leftChild;
        }else{
            cout<< p->data << endl;
            p = s.top();
            p = p->rightChild;
        }
    }
}
//后序遍历（递归实现）
void BTree::Postorder(BTNode* current){
    if(current != nullptr){
        Postorder(current->leftChild);
        Postorder(current->rightChild);
        cout<< current->data;
    }
}
//后序遍历（栈实现）
// void BTree::Postorder(BTNode* p){
//     stack<BTNode*> s;
//     while(p || !s.empty()){
//         if(p->leftChild){
//             s.push(p);
//             p = p->leftChild;
//         }else{
//             cout<< 
//         }
//     }
// }

//层次遍历
void BTree::LevelOrder(BTNode* current){
    queue<BTNode*> q;
    q.push(current);//根节点入队
    while(!q.empty()){
        current = q.front();
        q.pop();
        q.push(current->leftChild);//左孩子入队
        q.push(current->rightChild);//右孩子入队
    }
}

//计算节点数
int BTree::Count(BTNode* current){
    int lcnt, rcnt;
    if(current == nullptr)return 0;
    lcnt = Count(current->leftChild);
    rcnt = Count(current->rightChild);
    return lcnt + rcnt + 1;
}
//计算高度
int BTree::Height(BTNode* current){
    if(current == nullptr)return 0;
    else return max(Height(current->leftChild),Height(current->rightChild))+1;
}