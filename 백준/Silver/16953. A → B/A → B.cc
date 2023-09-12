#include <iostream>
#include <string>

using namespace std;

int a, b,cnt;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	while (1) {
		if (a > b) {
			cout << -1;
			break;
		}
		if (a == b) {
			cnt++;
			cout << cnt;
			break;
		}
		if (b % 10 == 1) {
			b--;
			b /= 10;
		}
		else if (b % 2 == 0) {
			b /= 2;
		}
		else {
			cout << -1;
			break;
		}
		cnt++;
	}

	return 0;
}