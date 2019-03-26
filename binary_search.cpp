#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m;
int a[500000];

/*
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.
*/
int binary_search(int num){
	int l=0;
	int r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==num)return 1;
		else if(a[mid]>num) r=mid-1;
		else l=mid+1;
	}
	return 0;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	scanf("%d",&m);
	while(m--){
		int num;
		scanf("%d",&num);
		printf("%d",binary_search(num));
	}
}
