#include <iostream>

using namespace std;

int N,ret;
int cow[11];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < 11; i++) {
		cow[i] = -1;
	}
	while (N--) {
		int a, b;
		cin >> a >> b;
		for (int i = 1; i <= 10; i++) {
			if (cow[a] == -1) {
				cow[a] = b;
			}
			else {
				if (cow[a] != b) {
					cow[a] = b;
					ret++;
				}
			}
		}
	}

	cout << ret;

	return 0;
}