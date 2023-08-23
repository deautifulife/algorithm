#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n;
	int b;
	int ans=0;

	cin >> n >> b;
	for (int i = n.length()-1; i >= 0; i--) {
		int tmp = n[i];
		if (tmp >= '0' && tmp <= '9')
			tmp = tmp - '0';
		else
			tmp = tmp + 10 - 'A';

		ans += tmp * pow(b, n.length() - i - 1);
	}

	cout << ans;

	return 0;
}