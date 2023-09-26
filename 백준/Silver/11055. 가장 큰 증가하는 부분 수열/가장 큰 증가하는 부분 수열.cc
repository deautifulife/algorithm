#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n;
int dp[1001];
int arr[1001];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max = 0;
	for (int i = 0; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}
		if (max < dp[i])
			max = dp[i];
	}

	cout << max;

	return 0;
}