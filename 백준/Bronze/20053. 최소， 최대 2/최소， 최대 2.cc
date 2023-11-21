#include <iostream>

using namespace std;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int maxn = -1000000;
		int minn = 1000000;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (num > maxn)
				maxn = num;
			if (num < minn)
				minn = num;
		}
		cout << minn << ' ' << maxn<<'\n';
	}
}