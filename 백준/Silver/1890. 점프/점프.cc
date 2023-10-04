#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
long long dp[100][100];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
	dp[0][0] = 1;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (dp[y][x] == 0 || (y == n - 1 && x == n - 1))
				continue;

			int value = map[y][x];
			int down = value + y;
			int right = value + x;

			if (down < n)
				dp[down][x] = dp[down][x] + dp[y][x];
			if (right < n)
				dp[y][right] = dp[y][right] + dp[y][x];
		}
	}
	cout << dp[n - 1][n - 1];
	

	return 0;
}