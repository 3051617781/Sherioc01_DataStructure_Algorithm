//@author 人工智能2201张杰 and ChatGPT
#include <iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){val = v; left = right = nullptr;}
};
/*
一开始的思路：
    1( 2(3,(4,5)), 6(7,8(9,10)) )
                 1
               /   \  
        2为父的树   6为父的树
考虑到子树的多种可能情况，分类讨论实现起来比较麻烦，所以舍弃这种写法。
TreeNode* createTree(string s){
    
    TreeNode* p = new TreeNode(s[0]);
    p->val = s[0];
    //提取出左子树对应字符串s1,右子树对应字符串s2
    stack<char> stk;
    int index;//记录逗号，确定分割出两个孩子的索引
    int len = 3;//考虑只有一个孩子的情况，需要利用长度确定子串
    for(int i = 1; i < s.size()-1; i++){//在 2(3,(4,5)), 6(7,8(9,10)) 中寻找分割的逗号
        index = 0;
        if(s[i] == '('){
            stk.push(s[i]);
            len++;
        } 
        else if(s[i] == ')'){
            stk.pop();
            len++;
            if(stk.empty())break;
        }
        if(s[i] == ','){
            len++;
            if(stk.empty())index = i;
        }

        if(index != 0)break;//找到逗号
    }

    if(index != 0){
        p->left = createTree(s.substr(2, index - 2));
        string rs = s.substr(index+1);//s右半部分
        p->right = createTree(s.substr(0,rs.size()-1));
    }
    else{
        p->left = createTree(s.substr(2, index-2));
        p->right = nullptr;
    }
    return p;
}
*/

/*
思路：使用堆栈存放上一级节点，遇到左括号则建立下层节点，右括号则弹栈
*/
TreeNode* createTree(string s){
    stack<TreeNode*> st;

    TreeNode* head = new TreeNode(s[0]-'0');//构建根节点
    TreeNode* t = head;//指向上一个节点

    int flag = 0;//逗号标志位

    for(int i = 1; i < s.size(); i++){
        //遇到左括号则把上一个节点压入栈中
        if(s[i] == '('){
            st.push(t);
        }
        //遇到右括号则top节点出栈
        if(s[i] == ')'){
            st.pop();
        }
        //遇到逗号则标志
        if(s[i] == ',')flag = 1;
        //遇到数字则建立节点
        if(isdigit(s[i]) && flag == 0){
            //数字处理
            int num = s[i]-'0';
            while(isdigit(s[++i])){
                num = num * 10 + ( s[i] - '0');
            }i--;

            t = st.top();
            t->left = new TreeNode(num);
            t = t->left;
        }
        if(isdigit(s[i]) && flag == 1){
            //数字处理
            int num = s[i]-'0';
            while(isdigit(s[++i])){
                num = num * 10 + ( s[i] - '0');
            }i--;

            t = st.top();
            t->right = new TreeNode(num);
            t = t->right;

            flag = 0;//flag置0，以后继续建立左节点
        }
    }
    return head;
}



/*
思路：使用vector存储每一层并将每一层放入栈中，最后弹出栈中所有元素
示意图
void levelOrder(TreeNode* root){
stack
    |4 5 6 7|
    |2 3    |  <--vector2
    |1      |  <--vector1
    |———————|
    stack<vector<TreeNode*>> s;
    TreeNode* p = root;
    while(p != nullptr){
        vector<TreeNode*> v;
        if(s.empty()){//如果栈s为空，则s单成数组，压入栈
            v.push_back(p);
            s.push(v);
        }else{//如果s不为空，则依次遍历栈顶的数组元素（父亲节点层）并将下层孩子放入数组，压入栈
            vector<TreeNode*> v_before = s.top();
            for(int i = 0; i < v_before.size(); i++){
                TreeNode* ptr = v_before.at(i);
                v.push_back(ptr->left);
                v.push_back(ptr->right);
            }
            s.push(v);
        }
    }

    //取栈s中每一层数组v，输出该层元素
    while(!s.empty()){
        vector<TreeNode*> v = s.top();
        for(int i = 0; i < v.size(); i++){
            cout<<v.at(i)->val;
        }
        cout<<'\n';
        s.pop();
    }

}
*/


/* 
@author GPT（此函数参考了ChatGPT）
Chatgpt给出了 广度优先搜索+队列的写法
要从下至上按层遍历二叉树并每层单独输出一行，可以使用广度优先搜索（BFS）算法和队列来实现。
*/
void levelOrderTraversal(TreeNode* root) {
    vector<int> v;
    if (root == NULL)
        return;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            
            // 输出节点值
            // cout << node->val << " ";
            v.push_back(node->val);//存入vector中
            
            // 将右、左子节点加入队列
            if (node->right)
                q.push(node->right);
            if (node->left)
                q.push(node->left);

        }
        
        // cout << endl;  // 换行
        v.push_back(-1);//将换行标志（-1）存入数组中
    }
    v.pop_back();//去除最后一个换行
    for(vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
        if(*it == -1)cout<<endl;
        else cout<<*it<<' ';
    }
}

int main() {
    string s;
    cin>>s;
    TreeNode* root = createTree(s);
    levelOrderTraversal(root);
    return 0;
}