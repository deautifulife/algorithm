#include <iostream>
#include <algorithm>

using namespace std;

int n;
int T[15], P[15];
int cache[15];

int solve(int day) {
	if (day > n)
		return -100000;
	if (day == n)
		return 0;

	int& ret = cache[day];
	if (ret != -1)
		return ret;

	ret = max(solve(day + 1), solve(day + T[day]) + P[day]);
	return ret;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> T[i] >> P[i];
		cache[i] = -1;
	}

	int ret = solve(0);
	cout<< ret;

	return 0;
}