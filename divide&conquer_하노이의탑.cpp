#include <cstdio>
/*
ù° �ٿ� �ű� Ƚ�� K�� ����Ѵ�.

�� ��° �ٺ��� ���� ������ ����Ѵ�. �� ��° �ٺ��� K���� �ٿ� ���� �� ���� A B�� ��ĭ�� ���̿� �ΰ� ����ϴµ�, �̴� A��° ž�� ���� ���� �ִ� ������ B��° ž�� ���� ���� �ű�ٴ� ���̴�.
*/

void solve(int n,int x, int y){
	if(n==0)return;
	solve(n-1,x,6-x-y);
	printf("%d %d",x,y);
	solve(n-1,6-x-y,y);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",(1<<n)-1);
	solve(n,1,3);
} 
