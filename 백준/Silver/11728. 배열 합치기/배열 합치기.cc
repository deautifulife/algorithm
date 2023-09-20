#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int a[1000001], b[1000001];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int ap = 0, bp = 0;

	while (ap < n && bp < m) {
		if (a[ap] <= b[bp]) {
			cout << a[ap++] << " ";
		}
		else
			cout << b[bp++] << " ";
	}
	//한 배열이 범위을 넘어섰는데 다른 배열은 남았을때
	while (ap < n) {
		cout << a[ap++] << " ";
	}
	while (bp < m) {
		cout << b[bp++] << " ";
	}
	return 0;
}