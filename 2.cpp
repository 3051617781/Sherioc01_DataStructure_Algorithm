#include <iostream>  
using namespace std;  
void heap_just(int arr[], int n, int i) {  
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    if (left < n && arr[left] > arr[largest])  
        largest = left;  
    if (right < n && arr[right] > arr[largest])  
        largest = right;  
    if (largest != i) {  
        swap(arr[i], arr[largest]);  
        heap_just(arr, n, largest);  
    }  
}  
  
void heap_sort(int arr[], int n) {  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heap_just(arr, n, i); 
    for (int i = n - 1; i >= 0; i--) {  
        swap(arr[0], arr[i]);  
        heap_just(arr, i, 0);   
    }  
}
  
int main() {  
    int n;
    printf("enter the n:");
    scanf("%d",&n);
    printf("enter n nums:");
    int arr[n];
    for(int i = 0; i < n; i++)scanf("%d",&arr[i]);
    heap_sort(arr, n);  
    for(int i = 0; i < n; i++)printf("%d ",arr[i]);
    return 0;  
}
