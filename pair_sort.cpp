#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cnt;
	scanf("%d", &cnt);
	vector <pair<int, int>> a(cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d %d", &a[i].first,&a[i].second);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) printf("%d %d\n", a[i].first, a[i].second);
}
