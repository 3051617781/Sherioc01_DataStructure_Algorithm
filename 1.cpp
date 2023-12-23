//@author zhangjie
#include<stdio.h>
using namespace std;

void quick_sort(int a[], int l, int r, int first_flag){
    int first_flag_index = 0; //the flag of first sort, middle element
    if(l<r){
        int i = l;
        int j = r;
        int flag = a[i]; //flag     
        while(i<j){
            while(i<j && a[j] >= flag){
                j--;
            }
            if(i<j){
                a[i++] = a[j];
            }
            while(i<j && a[i] < flag){
                i++;
            }
            if(i<j){
                a[j--] = a[i];
            }
        }
        a[i] = flag;
        first_flag_index = i;
        quick_sort(a,l,i-1,1);
        quick_sort(a,i+1,r,1);
    }
    if(first_flag == 0)printf("%d ",first_flag_index+1);
}

int main(){
    printf("只有"); 
    //input
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)scanf("%d",&a[i]);
    //quick_sort
    quick_sort(a,0,n-1,0);
    //output
    for(int i = 0; i < n; i++)printf("%d ",a[i]);
}
