#include <cstdio>
#include <algorithm>
using namespace std;
int heap[100001];
int hn;
/*
첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 입력되는 자연수는 2^31보다 작다.

출력
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 가장 큰 값을 출력하라고 한 경우에는 0을 출력하면 된다.
*/

int pop(){
	int ans=heap[1];
	heap[1]=heap[hn];
	heap[hn--]=0;
	for(int i=0;i*2<=hn;){
		if(heap[i]>heap[i*2]&&heap[i]>heap[i*2+1])break;
		else if(heap[i*2]>heap[i*2+1]){
			swap(heap[i],heap[i*2]);
			i=i*2;
		}
		else{
			swap(heap[i],heap[i*2+1]);
			i=i*2+1;
		}
	}
	return ans;
}

void push(int x){
	heap[++hn]=x;
	for(int i=hn;i>1;i/=2){
		if(heap[i/2]<heap[i]){
			swap(heap[i/2],heap[i]);
		}
		else break;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		if(x==0){
			if(hn==0)printf("0\n");
			else printf("%d\n",pop());
		}
		else push(x);
			
	}
	
}
