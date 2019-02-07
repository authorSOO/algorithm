#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Stack {
	int data[100001];
	int size;
	Stack() {
		size = 0;
	}
	void push(int num) {
		data[size++] = num;
	}
	bool empty() {
		if (!size)return true;
		else false;
	}
	int pop() {
		if (empty()) return -1;
		else return data[--size];
	}
	int top() {
		if (empty())return -1;
		else return data[size - 1];
	}
};

main() {
	int cnt;
	scanf("%d", &cnt);
	Stack s;
	while (cnt--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (cmd == "top") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
		}
		else if (cmd == "size") {
			cout << s.size << '\n';
		}
		else if (cmd == "empty") {
			cout << s.empty() << '\n';
		}
		else if (cmd == "pop") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
			if (!s.empty()) {
				s.pop();
			}
		}
	}
}
