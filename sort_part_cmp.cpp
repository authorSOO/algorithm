#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
	int x, y;
};
bool cmp(const Point &u, const Point &v) {
	if (u.x < v.x)return true;
	else if (u.x == v.x)return u.y < v.y;
	else return false;
}

int main() {
	int cnt;
	scanf("%d", &cnt);
	vector <Point> a(cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	sort(a.begin(), a.end(),cmp);
	for (int i = 0; i < a.size(); i++) printf("%d %d\n", a[i].x, a[i].y);
}
