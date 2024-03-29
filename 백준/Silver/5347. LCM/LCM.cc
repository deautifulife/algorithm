#include <iostream>

using namespace std;

int t;

int solve_gcd(long long a, long long b) {
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
	while (t--) {
		long long a, b;
		cin >> a >> b;
		cout<<a*b/solve_gcd(a, b)<<'\n';
	}

	return 0;
}