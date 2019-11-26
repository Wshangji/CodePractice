#include <iostream>
#include <cstring >
#include <cstdio>
#include <cmath>
using namespace std;
//�鲢����
void merge(int arr[], int l, int mid, int r){
	int help[r-l+1];//��������
	int i = 0;
	int lIndex = l;
	int rIndex = mid+1;
	while(lIndex <= mid && rIndex <= r){
		help[i++] = arr[lIndex] < arr[rIndex] ? arr[lIndex++]:arr[rIndex++];
	}
    //��ߺ��ұ߿϶���һ�ߵ�ͷ�ˣ�������ͬʱ����Ϊÿ��ֻ�ƶ�һ��
	while(lIndex <= mid){
		help[i++] = arr[lIndex++];
	}
	while(rIndex <= r){
		help[i++] = arr[rIndex++];
	}
    //���ź���ĸ������鸳ֵ��ԭʼ���飬����Ҫ����ֵ
	for(i = 0; i < r-l+1; i++){
		arr[l+i] = help[i];
	}
}

//�ݹ�
static void msort(int arr[], int l, int r){
	if(l == r){
		return;
	}
	int mid = (l + r) / 2;
    //��벿�ֹ鲢����
	msort(arr, l, mid);
    //�Ұ벿�ֹ鲢����
	msort(arr, mid+1, r);
    //���Ҳ��ֹ鲢
	merge(arr, l, mid, r);
}

//�鲢������������
 void msort(int arr[], int n){
    //�������Ϊ�ջ�ֻ��һ��Ԫ�أ�����Ҫ����
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
