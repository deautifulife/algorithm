#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n;
int dp[100001];
int arr[100001];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int max_dp = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		max_dp = max(max_dp, dp[i]);
	}

	cout << max_dp;

	return 0;
}