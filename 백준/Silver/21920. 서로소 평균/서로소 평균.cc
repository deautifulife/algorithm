#include <iostream>

using namespace std;

long long num[500001];
int n, x;

//유클리드 호제법
int Solvegcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return Solvegcd(b, a % b);
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> x;

	double total = 0;
	double cnt = 0;

	for (int i = 0; i < n; i++) {
		if (Solvegcd(num[i], x) == 1) {
			cnt++;
			total += num[i];
		}
	}

	cout << total / cnt;
	
	return 0;
}