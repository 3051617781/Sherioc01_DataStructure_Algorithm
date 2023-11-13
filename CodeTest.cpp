//@author 人工智能2201张杰、ChatGPT
/*
思路：
所有光缆的总长度尽量小（最小生成树）
岛屿之间的光缆同时开始铺设，某岛屿只要与主岛之间存在一条已经铺设好的电缆，就能接入互联网
1、不需要考虑生成问题，只需要找到最小生成树，
2、从mainland出发，子节点用时即为路径长度，并置为子节点的权
    孙节点用时即为max{与父节点路径长度，父节点的权}
*/
/*
计算最小生成树有两种算法：
使用kruskal算法：计算 n*(n-1)/2条边，排序，选取不构成回路的 n-1条边
使用prim算法：计算 (n-1)+2(n-2)+3(n-3)+...+(n-1)(n-1)条边
所以选择kruskal算法

ChatGPT部分：
在实现Kruskal算法过程中遇到了困难，借助chatgpt定义并查集结构并用kurskalMST函数实现生成最小生成树。

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct Edge{
    int src;
    int end;
    int weight;
};

bool cmp(Edge a, Edge b){
    return a.weight< b.weight;
}


//定义并查集结构DisjointSet用于判断两个节点是否在同一个连通分量中。
// 然后，在kruskalMST函数中遍历边的数组，对每条边进行判断，
// 如果两个节点不在同一个连通分量中，则将它们合并，并输出该边的信息。最终，我们可以得到最小生成树的边。
struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

vector<Edge> kruskalMST(vector<Edge>& edges, int n) {
    DisjointSet ds(n);
    vector<Edge>result;//返回最小生成树的边
    for (auto edge : edges) {
        int src = edge.src;
        int dest = edge.end;
        // int weight = edge.weight;
        
        int rootSrc = ds.find(src);
        int rootDest = ds.find(dest);
        
        if (rootSrc != rootDest) {
            //cout << src << " - " << dest << " 权重：" << weight << endl;
            result.push_back(edge);
            ds.merge(rootSrc, rootDest);
        }
    }
    return result;
}
vector<vector<int>> createResultArray(vector<Edge>& result, int n) {
    vector<vector<int>> result_arr(n, vector<int>(n, 0));
    for (auto edge : result) {
        int src = edge.src;
        int dest = edge.end;
        int weight = edge.weight;
        
        result_arr[src][dest] = weight;
        // result_arr[dest][src] = weight;
    }
    
    return result_arr;
}
int main(){
    int n;
    cin>>n;
    //存储每一个节点信息
    vector<vector<int>> graph(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
           cin >> graph[i][j]; 
        }
    }
    //edges数组存储边权重
    vector<Edge> edges(n*(n-1)/2);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            Edge edge;
            edge.src = i;
            edge.end = j;
            // 使用平方替代边
            edge.weight =  (graph[i][0]-graph[j][0])*(graph[i][0]-graph[j][0]) + (graph[i][1]-graph[j][1])*(graph[i][1]-graph[j][1]);
            edges.push_back(edge);
        }
    }
    //按权重从小到大排序各边
    sort(edges.begin(),edges.end(),cmp);
    //使用Kruskal算法生成最小生成树
    vector<Edge> result = kruskalMST(edges, n);
    // 将result中结果存放到数组中
    vector<vector<int>> result_arr = createResultArray(result, n);
    //计算权重
    vector<int> weight(n); //记录每个点权重
    for(int i = 0; i < n; i++){
            weight[i] = result_arr[0][i];
    }

    for(int i = 1; i < n; i++){//<0,x>点为最小时间
        for(int j = i+1; j < n; j++){
            if(result_arr[i][j] != 0){
                if(result_arr[i][j] > weight[i]){//<x,y>点用时大于<0,x>点，则最短时间为<x,y>点用时
                    weight[j] = result_arr[i][j];
                }else{
                    weight[j] = weight[i];
                }
            }
        }
    }


    //计算平均时间
    double time = 0;
    int total = 0;
    for(int i = 0; i < n; i++){
        time += sqrt(weight[i]) * graph[i][2]; //时间=权重*人数
        total += graph[i][2];
    }
    printf("%.2f",time/total);






    


    

}   