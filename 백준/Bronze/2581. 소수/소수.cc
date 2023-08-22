#include <iostream>
#include <cmath>

using namespace std;

int arr[10001];

int main() {

	int m, n;
	cin >> m >> n;
	int sum = 0;
	int min = 10001;
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i * i; j <= n; j += i)
			arr[j] = 0;
	}

	for (int i = m; i <= n; i++) {
		if (arr[i] != 0) {
			sum += arr[i];
			if (arr[i] < min)
				min = arr[i];
		}
	}

	if (sum == 0) {
		cout << "-1";
		return 0;
	}

	cout << sum << '\n';
	cout << min;

	return 0;
}