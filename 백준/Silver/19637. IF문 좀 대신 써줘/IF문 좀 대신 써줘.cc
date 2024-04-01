#include <iostream>

using namespace std;

int n, m;
int power[100000];
string title[100000];

int binsearch(int p) {
	int mid = 0, s = 0, e = n - 1;
	while (s <= e) {
		mid = (s + e) / 2;
		if (p <= power[mid])
			e = mid - 1;
		else
			s = mid + 1;
	}
	if (p > power[mid])
		return mid + 1;
	else
		return mid;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> title[i] >> power[i];
	}

	int p;
	for (int i = 0; i < m; i++) {
		cin >> p;
		cout << title[binsearch(p)]<<'\n';
	}

	return 0;
}