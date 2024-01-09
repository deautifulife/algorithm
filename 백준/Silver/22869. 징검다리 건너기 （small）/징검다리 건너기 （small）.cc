#include <iostream>

using namespace std;

int dp[5001];
int arr[5001];
int n, k;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = -1;
	}

	dp[1] = 1;
	for (int i = 1; i <= n-1; i++) {
		if (dp[i] == 1) {
			for (int j = i+1; j <= n; j++) {
				if (((j - i) * (1 + abs(arr[i] - arr[j])) < k)) {
					dp[j] = 1;
				}
			}
		}
	}

	if (dp[n] == 1) {
		cout << "YES";
	}
	else
		cout << "NO";




	return 0;
}