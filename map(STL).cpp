/*
����
�رԴ� ���� ī�� N���� ������ �ִ�. ���� ī�忡�� ������ �ϳ� �����ִµ�, �����ִ� ���� -262���� ũ�ų� ����, 262���� �۰ų� ����.

�ر԰� ������ �ִ� ī�尡 �־����� ��, ���� ���� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ����, ���� ���� ������ �ִ� ������ ���� �������, ���� ���� ����Ѵ�.

�Է�
ù° �ٿ� �ر԰� ������ �ִ� ���� ī���� ���� N (1 <= N <= 1000000)�� �־�����. ��° �ٺ��� N�� �ٿ��� ���� ī�忡 �����ִ� ������ �־�����.

���
ù° �ٿ� �ر԰� ���� ���� ������ �ִ� ������ ����Ѵ�.


*/

#include <cstdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	map<long long ,int> m;
	while(n--){
		long long x;
		scanf("%d",&x);
		d[x]++;
	}
	int max=0,ans;
	
	for(auto &p:m){
		if(p.second>max){
			max=p.second;
			ans=p.first;
		}
		else if(p.second==max&&p.first<ans) ans=p.first;
	}
	printf("%d",ans);
}
