#include <iostream>
using namespace std;
int main(){
	int data[100]={0};
	int sign[100]={0};
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>data[i];
		sign[i]=i;
	}
	sign[1]=n;
	sign[n]=1;
	for(int i=1; sign[i]!=0; i++)
		cout<<data[sign[i]  ]<<" ";
	return 0;
}
