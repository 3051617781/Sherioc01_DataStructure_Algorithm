// 单链表结构
#include<iostream>
using namespace std;
typedef int DataType;
class Item{
public:
    DataType data;
    Item* next;
    Item(){next = nullptr;}
};

class Link{ 
public:
    Item* head;                        //链表头指针
    /*头指针来标识一个单链表，如单链表L,指的是某链表的第一个结点的地址放在指针变量L中，
    头指针为“NULL”则表示一个空表。*/
    Link(){head=NULL; }                //构造函数
    ~Link(){DeleteAll(); }             //析构函数
    void Initiate();                  //初始化
    void DeleteAll();                 //删除所有结点
    void HeadCreate(int n);           //从头建链表
    void TailCreate(int n);           //从尾建链表
    void HeadCreateWithHead(int n);   //建立带表头的链表(从头)
    void TailCreateWithHead(int n);   //建立带表头的链表(从尾)
    int Length();                     //求链表长度
    Item* Locatex(DataType x);        //查找值为x的数据元素
    Item* Locatei(int i);             //查找第i个元素
    DataType Get(int i);              //取第i个元素值
    bool Insert(DataType x, int i);    //在链表第i个结点之前插入x
    bool Deleted(int i);              //删除链表中第i个结点
    void Print();                     //打印链表
};
//链表初始化
void Link::Initiate(){
    DeleteAll();
    head = nullptr;
}
//建立单链表(不带有空白头节点)
void Link::TailCreate(int n){
    DeleteAll();
    Item *s, *p;//p指向头，s指向节点
    p = nullptr;
    for(int i = 0; i < n; i++){
        s = new Item();
        cin>>s->data;
        s->next = p;
        p = s;
    }
    head = p;
}

void Link::HeadCreate(int n){
    DeleteAll();
    Item *s, *p, *r;//p指向头，r指向尾
    p = nullptr;
    for(int i = 0; i < n; i++){
        s = new Item();
        cin>>s->data;
        if(p == nullptr)p = r = s;
        else{
            r->next = s;
            r = s;
        }
    }
    head = p;
}
//建立单链表（带有空白头节点）
/*头结点的加入完全是为了运算的方便。它的数据域无定义，
指针域中存放的是第一个数据元素的地址，空表时指针域为空。*/
void Link::TailCreateWithHead(int n){
    Item* s,* p;
    DeleteAll();
    p = new Item();
    for(int i = 0; i < n; i++){
        s = new Item();
        cin>>s->data;
        s->next = p->next;
        p->next = s;
    }
    head = p;
}

void Link::HeadCreateWithHead(int n){
    Item* s, * r, * p;
    DeleteAll();
    p = new Item();
    r = p;
    for(int i = 0; i < n; i++){
        s = new Item();
        cin>>s->data;
        r->next = s;
        r = s;
    }
    r->next = nullptr;
    head = p;
} 
using namespace std;
int main(){
    cout<<"hello";
}