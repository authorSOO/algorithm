#include <algorithm>
#include <iostream>
#include <vector>
/*
ù° �ٿ� ���� ���� N (2 �� N �� 200,000)�� �������� ���� C (2 �� C �� N)�� �ϳ� �̻��� �� ĭ�� ���̿� �ΰ� �־�����. ��° �ٺ��� N���� �ٿ��� ���� ��ǥ�� ��Ÿ���� xi (1 �� xi �� 1,000,000,000)�� �� �ٿ� �ϳ��� �־�����.

ù° �ٿ� ���� ������ �� ������ ������ �ִ� �Ÿ��� ����Ѵ�.
*/
using namespace std;
bool possible(vector<int> &a, int c, int x) {
    int cnt = 1;
    int last = a[0];
    for (int house : a) {
        if (house - last >= x) {
            cnt += 1;
            last = house;
        }
    }
    return cnt >= c;
}
int main() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 1;
    int r = a[n-1] - a[0];

    int ans = l;
    while(l <= r) {
        int mid = (l+r)/2;
        if (possible(a, c, mid)) {
            if (ans < mid) {
                ans = mid;
            }
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
