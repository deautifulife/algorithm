#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;
int minNum = 100000000;

void twoCommonFactor(int a, int b) {
	if (a > b)
		minNum = b;
	else
		minNum = a;

	for (int i = 1; i <= minNum; i++) {
		if (a % i == 0) {
			if (b % i == 0)
				ans.push_back(i);
		}
	}
}

void threeCommonFactor(int a, int b, int c) {
	if (a < b && a < c)
		minNum = a;
	else if (b < a && b < c)
		minNum = b;
	else if (c < a && c < b)
		minNum = c;

	for (int i = 1; i <= minNum; i++) {
		if (a % i == 0) {
			if (b % i == 0) {
				if (c % i == 0)
					ans.push_back(i);
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	if (n == 2) {
		int a, b;
		cin >> a >> b;
		twoCommonFactor(a, b);
	}
	else if (n == 3) {
		int a, b, c;
		cin >> a >> b >> c;
		threeCommonFactor(a, b, c);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}