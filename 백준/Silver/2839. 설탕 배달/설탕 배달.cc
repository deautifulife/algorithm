#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[5001];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	dp[3] = dp[5] = 1;

	for (int i = 6; i <= n; i++) {
		if (dp[i - 3])
			dp[i] = dp[i - 3] + 1;

		if (dp[i - 5]) {
			if (dp[i] == 0)
				dp[i] = dp[i - 5] + 1;
			else
				dp[i] = min(dp[i], dp[i - 5] + 1);
		}
	}

	if (dp[n] == 0)
		cout << "-1";
	else
		cout << dp[n];
	

	return 0;
}