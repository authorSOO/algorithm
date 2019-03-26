#include <cstdio>
#include <algorithm>
using namespace std;
int heap[100001];
int hn;
/*
ù° �ٿ� ������ ���� N(1��N��100,000)�� �־�����. ���� N���� �ٿ��� ���꿡 ���� ������ ��Ÿ���� ���� x�� �־�����. ���� x�� �ڿ������ �迭�� x��� ���� �ִ�(�߰��ϴ�) �����̰�, x�� 0�̶�� �迭���� ���� ū ���� ����ϰ� �� ���� �迭���� �����ϴ� ����̴�. �ԷµǴ� �ڿ����� 2^31���� �۴�.

���
�Է¿��� 0�� �־��� ȸ����ŭ ���� ����Ѵ�. ���� �迭�� ��� �ִ� ����ε� ���� ū ���� ����϶�� �� ��쿡�� 0�� ����ϸ� �ȴ�.
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
