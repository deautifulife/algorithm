#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<vector<int>> v;
int dp[22][3];

int recur(int cur, int chance) {
	int ret = 9999999;

	if (dp[cur][chance] != -1) {
		return dp[cur][chance];
	}

	if (cur > n)
		return 999999999;
	if (cur == n)
		return 0;

	//작은 점프, 큰 점프, 매우 큰 점프 중 최솟값을 찾는다.
	if (chance == 0) {
		ret = min(ret, recur(cur + 3, 1) + k);
	}
	ret = min(ret, recur(cur + 2, chance) + v[cur][1]);
	ret = min(ret, recur(cur + 1, chance) + v[cur][0]);

	dp[cur][chance] = ret;

	return dp[cur][chance];

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	fill(&dp[0][0], &dp[21][3], -1);
	v.resize(n + 1, vector<int>());

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		v[i] = { a,b };
	}
	cin >> k;

	cout << recur(1, 0);

	return 0;
}