#include <algorithm>
#include <iostream>
#include <vector>
/*
첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다. 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (1 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.

첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.
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
