//区间贪心
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100;
struct Interval{
    int x, y;//开区间左右端点
}I[maxn];
bool cmp(Interval a, Interval b){
    if(a.x != b.x)return a.x > b.x;//按左端点从大到小排序
    else return a.y < b.y;//按右端点从小到大排序
}
int main(){
    int n;
    while(scanf("%d", &n), n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d%d",&I[i].x, &I[i].y);
        }
        sort(I, I + n, cmp);
        //ans记录不相交区间个数，lastX记录上一个被选中的左端点
        int ans = 1, lastX = I[0].x;
        for(int i = 1; i < n; i++){
            if(I[i].y <= lastX){
                ans++;
                lastX = I[i].x;
            }
        }
        printf("%d",ans);
    }
}