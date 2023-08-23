#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//유클리드 호제법
int Solvegcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return Solvegcd(b, a % b);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	int a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << a * b / Solvegcd(a, b) << '\n';
	}

	return 0;
}