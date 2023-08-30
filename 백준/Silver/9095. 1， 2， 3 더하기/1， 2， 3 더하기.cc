#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int t;
vector<int> v;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int max = -1;

	cin >> t;
	while (t--) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		if (max < tmp)
			max = tmp;
	}

	vector<int> dp(max+1);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4; //111,12,21,3

	for (int i = 4; i <= max; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}


	for (int i = 0; i < v.size(); i++) {
		cout << dp[v[i]] << '\n';
	}

	return 0;
}