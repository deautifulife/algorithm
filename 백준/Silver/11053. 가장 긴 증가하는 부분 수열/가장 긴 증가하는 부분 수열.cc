#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int dp[1001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		dp[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	sort(dp, dp+n);
	cout << dp[n-1];

	return 0;
}