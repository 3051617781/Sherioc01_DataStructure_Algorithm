#include<stdio.h>
#include<string.h>
#include<math.h>
/*
分析：

本题可用之前分析的Prim最小生成树来生成路径，之后的关键就是在找到这些边的时候记录下这些边，并算出需要等待的时间。

需要等待的时间——

若岛A直接连接到主岛，则A岛需要等待的时间就是二者的距离

假设A通过B连接到主岛，

如果A到B的边长小于B到主岛的边长，则A岛等的时间实际上是B到主岛的时间

否则如果A到B的边长大于B到主岛的边长，则A岛等的时间是A岛修光缆到B岛的时间
————————————————
版权声明：本文为CSDN博主「puppylpg」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/puppylpg/article/details/41695677
*/ 
#define INF 0xfffffff							// infinity
#define MAXSIZE 20
 
int n;
int people[MAXSIZE], point[MAXSIZE][2];			//point[]记录点的坐标位置
double edge[MAXSIZE][MAXSIZE], time[MAXSIZE];	//因为每天铺一公里，所以time[]其实就是距离
 
void Prim(double edge[][MAXSIZE], int u);
double distance(int a, int b, int c, int d);
 
int main()
{
	int i, j;
	int sum_people = 0;
	double sum_time = 0;
 
	memset(edge, 0, sizeof(edge));				// void * memset (void * p,int c,size_t n)
	scanf("%d", &n);
	for(i = 1; i <= n; i++)						//读点的坐标和人数
		scanf("%d%d%d", &point[i][0], &point[i][1], &people[i]);
 
    for(i = 1; i <= n; i++)						//计算总人数
        sum_people += people[i];
 
	for(i = 1; i <= n; i++)						// 构造邻接矩阵
		for(j = 1; j <= n; j++)
			edge[i][j] = edge[j][i] = distance(point[i][0], point[i][1], point[j][0], point[j][1]);
 
	Prim(edge, 1);						//Prim算法，从主岛（顶点1）开始
 
	for(i=2; i<=n; i++)					//计算所有人等待的总时间（主岛除外），故i=2
		sum_time += time[i] * people[i];
 
	printf("%.2f\n", sum_time / sum_people);
	return 0;
}
 
void Prim(double edge[][MAXSIZE], int u)
{
	int nearvex[MAXSIZE] = {0};
	double lowcost[MAXSIZE] = {0}, mincost = INF * 1.0;
	int i, j;
	int v = -1;
	double weight = 0;
 
	for(i=1; i<=n; i++)							//NO.1 对距离进行初始化
	{
		lowcost[i] = edge[u][i];
		nearvex[i] = u;
	}
	lowcost[u] = 0;
	nearvex[u] = -1;
 
	for(i=1; i<n; i++)					//NO.4 循环n-1次，加入n-1个顶点
	{
        mincost = INF;		// very important!!!!! EVERY TIME mincost should be initialized to find the minimum
		for(j=1; j<=n; j++)				//NO.3 更新距离，找到边的权值最小的那个点
			if(nearvex[j] != -1 && lowcost[j] < mincost)
			{
				mincost = lowcost[j];
				v = j;				//记录下这个边的权值最小的点
			}
 
		if(v != -1)					//如果找到那个点，进行NO.2
		{
	//		printf("%d--(%f)-->%d\n", nearvex[v], lowcost[v], v);   //打印加入的流程
//****************************************************************************************************************
//相对于最小生成树的关键代码：
			if(nearvex[v] == u)				//若毗邻主岛，直接将时间（距离）更新为边长
				time[v] = lowcost[v];
			else if(lowcost[v] <= time[ nearvex[v] ])
				time[v] = time[ nearvex[v] ];
				else
					time[v] = lowcost[v];
//假设A通过B连接到主岛，如果A到B的边长小于B到主岛的边长，则A岛等的时间实际上是B到主岛的时间
//否则如果A到B的边长大于B到主岛的边长，则A岛等的时间是A岛修光缆到B岛的时间
//****************************************************************************************************************
 
			nearvex[v] = -1;					//将点加入T2
			weight += lowcost[v];
 
			for(j=1; j<=n; j++)					//加入后，对距离进行更新
			{
				if(nearvex[j] != -1 && edge[v][j] < lowcost[j])
				{
					lowcost[j] = edge[v][j];
					nearvex[j] = v;
				}
			}
		}
	}
}
 
double distance(int a, int b, int c, int d)
{
	return sqrt( (a-c)*(a-c) + (b-d)*(b-d) );
}