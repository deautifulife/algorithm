#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int ret = 4;
	int sqrtN = sqrt(n);

	for (int a = 1; a <= sqrtN; a++) {
		if (a * a == n) {
			ret = 1;
			break;
		}

		for (int b = 1; b <= sqrtN; b++) {
			if (a * a + b * b > n) {
				break;
			}
			if (a * a + b * b == n) {
				ret = 2;
			}
			if (ret <= 2)
				break;

			for (int c = 1; c <= sqrtN; c++) {
				if (a * a + b * b + c * c > n) {
					break;
				}

				if (a * a + b * b + c * c == n) {
					ret = 3;
					break;
				}
			}
		}
	}

	cout << ret;

	return 0;
}