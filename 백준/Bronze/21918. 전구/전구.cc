#include <iostream>

using namespace std;

int N, M;
int bulb[4001];

void command(int a, int b, int c) {
	if (a == 1) {
		bulb[b] = c;
	}
	else if (a == 2) {
		for (int i = b; i <= c; i++) {
			if (bulb[i] == 0)
				bulb[i] = 1;
			else if (bulb[i] == 1)
				bulb[i] = 0;
		}
	}
	else if (a == 3) {
		for (int i = b; i <= c; i++) {
			bulb[i] = 0;
		}
	}
	else if (a == 4) {
		for (int i = b; i <= c; i++) {
			bulb[i] = 1;
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> bulb[i];
	}
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		command(a, b, c);
	}
	for (int i = 1; i <= N; i++) {
		cout << bulb[i]<<' ';
	}

	return 0;
}