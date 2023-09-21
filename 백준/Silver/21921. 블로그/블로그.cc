#include <iostream>
#include<vector>

using namespace std;

int n, x;
int visited[250001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> visited[i];
	}

	int begin = 0;
	int end = x-1;
	int sum = 0;

	for (int i = begin; i <= end; i++) {
		sum += visited[i];
	}
	int maxvisited = sum;
	int firstsum = sum;
	int cnt = 1;

	while (end < n-1) {
		sum = sum - visited[begin++] + visited[++end];
		
		if (sum > maxvisited) {
			maxvisited = sum;
			cnt = 1;
		}
		else if (sum == maxvisited) {
			cnt++;
		}
	}
	if (maxvisited == 0) {
		cout << "SAD";
	}
	else {
		cout << maxvisited << '\n' << cnt;
	}

	return 0;
}