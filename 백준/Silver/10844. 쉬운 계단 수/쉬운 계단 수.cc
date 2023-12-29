#include <iostream>

using namespace std;

int N;
long long dp[101][10]; //dp[a][b] = c, 길이가 a인 숫자에서, 마지막 자리가 b로 끝나는 쉬운 계단 수는 총 c개가 있다.


void solution() {
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][8];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] = dp[i][j] % 1000000000;
		}
	}

	long long ret = 0;
	for (int i = 0; i <= 9; i++)
		ret = ret + dp[N][i];
	ret = ret % 1000000000;

	cout << ret << '\n';

	return 0;
}