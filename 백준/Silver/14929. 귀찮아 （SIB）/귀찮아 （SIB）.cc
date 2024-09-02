#include <iostream>

using namespace std;

int n;
long long map[100001];
long long sum[100001];
long long ret;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	//누적 합
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
		sum[i] = sum[i - 1] + map[i];
	}

	//i가 1부터 N까지인 i번째 수와 i+1번째 수부터 N번째 수까지의 합의 곱을 더해준다.
	for (int i = 1; i < n; i++) {
		ret += (sum[n] - sum[i]) * map[i];
	}

	cout << ret << '\n';

	return 0;
}