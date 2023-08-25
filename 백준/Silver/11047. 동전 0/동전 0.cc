#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> coin;
int ea;

bool compare(int a, int b) {
	return a > b;
}
int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		coin.push_back(input);
	}

	sort(coin.begin(), coin.end(), compare);

	for (int i = 0; i < n; i++) {
		while (coin[i] <= k) {
			k -= coin[i];
			ea++;
		}
	}

	cout << ea;

	return 0;
}