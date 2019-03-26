#include <iostream>

/*
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
*/

using namespace std;
int go(int count, int sum, int goal) {
    if (count > 10) {
        return 0;
    }
    if (sum > goal) {
        return 0;
    }
    if (sum == goal) {
        return 1;
    }
    int now = 0;
    for (int i=1; i<=3; i++) {
        now += go(count+1, sum+i, goal);
    }
    return now;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << go(0, 0, n) << '\n';
    }
    return 0;
}
