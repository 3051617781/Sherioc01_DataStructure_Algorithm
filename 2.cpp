#include <iostream>  
using namespace std;  
//使用大根堆
void heap_just(int arr[], int n, int i) {  
    int largest = i; // 初始化根节点索引为最大值  
    int left = 2 * i + 1; // 左子节点 
    int right = 2 * i + 2; // 右子节点 
    // 如果左子节点比根节点大，则更新最大值索引  
    if (left < n && arr[left] > arr[largest])  
        largest = left;  
    // 如果右子节点比根节点大，则更新最大值索引  
    if (right < n && arr[right] > arr[largest])  
        largest = right;  
    // 如果最大值不是根节点，则交换它们并继续堆化  
    if (largest != i) {  
        swap(arr[i], arr[largest]);  
        heap_just(arr, n, largest);  
    }  
}  
  
void heap_sort(int arr[], int n) {  
    // 构建大根堆
    for (int i = n / 2 - 1; i >= 0; i--)  
        heap_just(arr, n, i); 
    // 从最后一个元素开始，将其与根节点交换并重新构建大根堆 
    for (int i = n - 1; i >= 0; i--) {  
        swap(arr[0], arr[i]); // 将根节点与当前元素交换  
        heap_just(arr, i, 0); // 对前 i 个元素重新堆化  
    }  
}
  
int main() {  
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)scanf("%d",&arr[i]);
    heap_sort(arr, n);  
    for(int i = 0; i < n; i++)printf("%d ",arr[i]);
    return 0;  
}
