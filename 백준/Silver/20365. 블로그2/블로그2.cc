#include <iostream>

using namespace std;

int n;
char q[500001];
int cb, cr;
int ans;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int cnt = 0;
	char tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (i > 0 && tmp == q[cnt - 1]) {
			continue;
		}
		else {
			q[cnt] = tmp;
			if (q[cnt] == 'B')
				cb++;
			else if (q[cnt] == 'R')
				cr++;
			cnt++;
		}
	}

	if (cb > cr) {
		ans = cr + 1;
	}
	else {
		ans = cb + 1;
	}

	cout << ans;


	return 0;
}