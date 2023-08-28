#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long price[100001];
long long meter[100001];
long long ans;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> meter[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	for (int i = 0; i < n - 1; i++) {
		if (price[i] > price[i + 1]) {
			ans += price[i] * meter[i];
		}
		else {
			ans += (price[i] * meter[i]) + (price[i] * meter[i + 1]);
			i++;
		}
	}

	cout << ans;

	return 0;
}