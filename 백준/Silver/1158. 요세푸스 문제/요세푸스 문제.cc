#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
vector<int> ret;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i = 0; i < k; i++) {
			if (i == k-1) {
				ret.push_back(q.front());
				q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}

	cout << "<";
	for (int i = 0; i < ret.size(); i++) {
		if (i == ret.size() - 1) {
			cout << ret[i];
			break;
		}
		cout << ret[i] << ", ";
	}
	cout << ">";

	return 0;
}