#include <cstdio>
/*
첫째 줄에 옮긴 횟수 K를 출력한다.

두 번째 줄부터 수행 과정을 출력한다. 두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데, 이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다.
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
