#include <iostream>
#include <cmath>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	cin >> n;


	long long s = 0;
	long long e = sqrt(n);
	long long mid = (s + e) / 2;

	while (s <= e) {
		mid = (s + e) / 2;

		if (mid * mid > n) {
			e = mid - 1;
		}
		else if (mid * mid < n) {
			s = mid + 1;
		}
		else
			break;
	}

	if (n > mid * mid)
		mid++;

	cout << mid;

	return 0;
}