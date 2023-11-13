# 线性表

## 线性表的基本运算

```cpp
初始化运算      init()
求表长度       length(L)
取表中元素      get(L, i)
定位           locate(L, x)
插入            insert(L, x)
删除            del(L, x)
```
## 线性表的顺序存储

### 顺序表的实现

```cpp
typedef int DataType
typedef struct {
    DataType *data; //首地址
    int last;       //最后一个元素下标, n = last + 1
    int MaxSize;    //最大允许长度
}List
```
### 顺序表的初始化

```cpp
int init(List *L, int ms){
    L->data = (DataType *)malloc(sizeof(DataType) * ms);
    if(L->data){
        L->MaxSize = ms;
        L->last = -1;
        return 1; //成功初始化，返回1
    }
    return 0; //分配失败
}
```
### 顺序表取表中元素

```cpp
int get(List *L, int i){
    if(i < 0 || i > L->last)return 0;
    return L->data[i];
}
```
### 顺序表定位

```cpp
int locate(List *L, DataType x){
    for(int i = 0; i < List->last; i++){
        if(L->data[i] == x)return i;
    }
    return -1;
}
```
### 顺序表插入

```cpp
int insert(List *L, int i, DataType x){
    if(i < 0 || i > L->last + 1)return 0;
    if(L->MaxSize == L->last + 1)return 0;
    for(int j = L->last, j >= i; j--){
        L->data[j + 1] = L->data[j];
    }
    L->data[i] = x;
    L->last++;
    return 1;
}
```
### 顺序表删除

```cpp
int del(List *L, int i){
    if(i<0 || i > L->last)return 0;
    for(int j = i; j < L->last - 1; j++){
        L->data[j] = L->data[j + 1]
    }
    return 1;
}
```
## 顺序表的链式存储

### 链表的实现

```cpp
typedef struct node{
    DataType data;
    node * next;
}LinkList;
```
### 链表的初始化

```cpp
LinkList *init(){
    LinkList *head;
    head = (LinkList *)malloc(sizeof(LinkList));
    head->next = null; //带有头节点
    return head;
}
```
### 头插法建立单链表

```cpp
LinkList *init_head(){
    LinkList * head, * p;
    head = (LinkList*)malloc(sizeof(LinkList));
    head->next = null;
    DataType x;
    scanf("%d",&x);
    while(x != -1){
        p = (LinkList*)malloc(sizeof(LinkList));
        p->data = x;
        p->next = head->next;
        head->next = p;
        scanf("%d",&x);
    }
    return head;
}
```
### 尾插法建立单链表

```cpp
LinkList *init_tail(){
    LinkList * head, * p, *rear; //rear为尾指针指向最后一个节点
    head = (LinkList*)malloc(sizeof(LinkList));
    head->next = null;
    rear = head;
    DataType x;
    scanf("%d",&x);
    while(x != -1){
        p->data = x;
        p->next = null;
        rear->next = p;
        rear = rear->next; //同rear = p; 使rear指向最后一个节点
        scanf("%d",&x);
    }
}
```
### 单链表取元素

```cpp
LinkList get(LinkList *head, int i){
    LinkList *p = head;
    while(i--)p = p->next;
    return p;
}

```