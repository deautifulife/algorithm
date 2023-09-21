#include <iostream>
#include<vector>

using namespace std;

int t, n;
int sti[2][100001];
int dp[2][100001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j < n; j++) {
				cin >> sti[i][j];
			}
		}
		dp[0][0] = sti[0][0];
		dp[1][0] = sti[1][0];
		dp[0][1] = sti[1][0] + sti[0][1];
		dp[1][1] = sti[0][0] + sti[1][1];
		for (int i = 2; i < n; i++) {
			dp[0][i] = sti[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
			dp[1][i] = sti[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
		}
		cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
	}



	return 0;
}