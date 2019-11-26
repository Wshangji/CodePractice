/*
*折半查找，使用的是二分的思想
*@auther by wyt
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

void qsort(int *a, int l, int r);
bool search(int k, int *a, int l, int r);

int main(){
	int a[100],k,n;
	bool b;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	qsort(a, 0, n-1);
	cin>>k;
	b=search(k, a, 0, n-1);
	if(b)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

void qsort(int *a, int l, int r) {
	int i, j, mid, t;
	i = l;
	j = r;
	mid = a[(l + r) / 2];
	do {
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			t--;
		}
	} while (i <= j);
	if (j > l) qsort(a, l, j);
	if (i < r) qsort(a, i, r);
}

bool search(int k, int *a, int l, int r){
	while(l <= r){
		int mid = (l+r)/2;
		if(a[mid] == k)
			return true;
		else if(a[mid] < k)
			l = mid+1;
		else
			r = mid-1;
	}
	return false;
}
