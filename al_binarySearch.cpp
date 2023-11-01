//二分查找
#include<cstdio>
using namespace std;
int binarySearch(int a[], int left, int right, int x){//左闭右闭，无重复元素，传入区间为【0，n-1】
    int mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(a[mid] == x)return mid;
        else if(a[mid] > x)right = mid - 1;
        else left = mid + 1;
    }
    return -1;//未找到
}

int binarySearch_Multiple(int a[], int left, int right, int x){//左闭右闭，有重复元素，传入区间为【0，n】
    //求出第一个等于x的位置L，第一个大于x的位置R，则[L,R)；如果x不存在，则L、R为x应该存在的位置

    /*
    //求左边界L
    
    int lower_bound(int a[], int left, int right, int x){
        int mid;
        while(left < right){
            mid = (left + right) / 2;
            if(a[mid] >= x){
                right = mid;
            }else left = mid + 1;

        }
        return left;//或者right
    }
        
    //求右边界R
    int upper_bound(int a[], int left, int right, int x){
        int mid;
        while(left < right){
            mid = (left + right) / 2;
            if(a[mid] > x)right = mid;
            else left = mid + 1;
        }
        return left;//或者right
    }
    */
}


int main(){
    int n = 9;
    int a[n] = {1,3,4,7,8,9,14,17,19};
    printf("%d",binarySearch(a, 0, n - 1, 7));
}

