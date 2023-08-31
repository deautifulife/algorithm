#include <iostream>
//#include <queue>
#include <algorithm>

using namespace std;

long long musless[10001];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long m,max;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> musless[i];
	}

	sort(musless, musless + n);

	if (n % 2 != 0) {
		max = musless[n - 1];
		for (int i = 0; i < n / 2; i++) {
			m = musless[i] + musless[n - 2 - i];
			if (m > max)
				max = m;
		}
	}

	else {
		max = -1;
		for (int i = 0; i < n / 2; i++) {
			m = musless[i] + musless[n - i -1];
			if (m > max)
				max = m;
		}
	}
	

	

	cout << max;
	return 0;
}