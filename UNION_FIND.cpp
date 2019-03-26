/*
ù° �ٿ� n(1��n��1,000,000), m(1��m��100,000)�� �־�����. 
m�� �Է����� �־����� ������ �����̴�. ���� m���� �ٿ��� ������ ������ �־�����. 
�������� 0 a b�� ���·� �Է��� �־�����. �̴� a�� ���ԵǾ� �ִ� ���հ�, b�� ���ԵǾ� �ִ� ������ ��ģ�ٴ� �ǹ��̴�. 
�� ���Ұ� ���� ���տ� ���ԵǾ� �ִ����� Ȯ���ϴ� ������ 1 a b�� ���·� �Է��� �־�����.
 �̴� a�� b�� ���� ���տ� ���ԵǾ� �ִ����� Ȯ���ϴ� �����̴�. a�� b�� n ������ �ڿ����Ǵ� 0�̸� ���� ���� �ִ�.


1�� �����ϴ� �Է¿� ���ؼ� �� �ٿ� �ϳ��� YES/NO�� ����� ����Ѵ�. (yes/no �� ����ص� �ȴ�)
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
