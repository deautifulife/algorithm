#include <iostream>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long s;
	int cnt = 0;
	long long sum = 0;

	cin >> s;

	for (int i = 1; i <= s; i++) {
		sum += i;
		cnt++;
		if (sum > s) {
			cnt--;
			break;
		}
		else if (sum == s) {
			break;
		}
	}

	cout << cnt;

	return 0;
}