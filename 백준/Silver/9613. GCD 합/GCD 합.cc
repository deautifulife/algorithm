#include <iostream>

using namespace std;

int t,n;
long long arr[101];
long long ret[101];

int solve_gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return solve_gcd(b, a % b);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	int retsize = 0;
	for(int tnum=0; tnum<t; tnum++){
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int j = 0; j < n-1; j++) {
			for (int k = j + 1; k < n; k++) {
				ret[tnum] += solve_gcd(arr[j], arr[k]);
			}
		}
	}

	for (int i = 0; i < t; i++) {
		cout << ret[i] << '\n';
	}
	return 0;
}