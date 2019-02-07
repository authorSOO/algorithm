#include <iostream>
using namespace std;
int a[100001];

void swap(int &x,int &y){
	int z=x;
	x=y;
	y=z;
}

int translate(int low,int high){
	int mid=low + (high-low)/2;
	int	value = a[mid];
	int pointer=low;
	swap(a[mid],a[high]);
	for(int i=low;i<high;i++){
		if(a[i]<value) swap(a[pointer++],a[i]);
	}
	
	swap(a[pointer],a[high]);
	return pointer;
}


void quicksort(int low,int high){
	if(low<high){
		int pivot=translate(low,high);
		quicksort(low,pivot-1);
		quicksort(pivot+1,high);
	}
}

int main() {
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%d", &a[i]);
	}
	quicksort(0,cnt-1);

	for (int i = 0; i < cnt; i++) printf("%d ", a[i]);
}
