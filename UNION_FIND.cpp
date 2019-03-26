/*
첫째 줄에 n(1≤n≤1,000,000), m(1≤m≤100,000)이 주어진다. 
m은 입력으로 주어지는 연산의 개수이다. 다음 m개의 줄에는 각각의 연산이 주어진다. 
합집합은 0 a b의 형태로 입력이 주어진다. 이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다. 
두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다.
 이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다. a와 b는 n 이하의 자연수또는 0이며 같을 수도 있다.


1로 시작하는 입력에 대해서 한 줄에 하나씩 YES/NO로 결과를 출력한다. (yes/no 를 출력해도 된다)
*/
#include <cstdio>
int parent[1000001];
int Find(int x){
	if(x==parent[x])return x;
	else return parent[x]=Find(parent[x]);
}

void Union(int x, int y){
	x=Find(x);
	y=Find(y);
	if(x!=y){
		parent[y]=x;
	}
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;i++){
		parent[i]=i;
	}
	while(m--){
		int w,x,y;
		scanf("%d %d %d",&w,&x,&y);
		if(w==0){
			Union(x,y);
		}
		else{
			x=Find(x);
			y=Find(y);
			if(x==y)printf("yes\n");
			else printf("no\n");
		}
		
	}
	
}
