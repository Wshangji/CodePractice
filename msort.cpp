#include <iostream>
#include <cstring >
#include <cstdio>
#include <cmath>
using namespace std;
//归并过程
void merge(int arr[], int l, int mid, int r){
	int help[r-l+1];//辅助数组
	int i = 0;
	int lIndex = l;
	int rIndex = mid+1;
	while(lIndex <= mid && rIndex <= r){
		help[i++] = arr[lIndex] < arr[rIndex] ? arr[lIndex++]:arr[rIndex++];
	}
    //左边和右边肯定有一边到头了，不可能同时，因为每次只移动一边
	while(lIndex <= mid){
		help[i++] = arr[lIndex++];
	}
	while(rIndex <= r){
		help[i++] = arr[rIndex++];
	}
    //将排好序的辅助数组赋值给原始数组，不需要返回值
	for(i = 0; i < r-l+1; i++){
		arr[l+i] = help[i];
	}
}

//递归
static void msort(int arr[], int l, int r){
	if(l == r){
		return;
	}
	int mid = (l + r) / 2;
    //左半部分归并排序
	msort(arr, l, mid);
    //右半部分归并排序
	msort(arr, mid+1, r);
    //左右部分归并
	merge(arr, l, mid, r);
}

//归并排序整个数组
 void msort(int arr[], int n){
    //如果数组为空或只有一个元素，不需要排序
	if(arr == NULL || n < 2){
		return;
	}
	msort(arr,0,n-1);
}

int main(){
    int arry[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arry[i];
    msort(arry, n);
    for(int i=0; i<n; i++)
        cout<<arry[i]<<" ";
    return 0;
}
