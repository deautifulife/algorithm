#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int price[100001];
vector<int> price;

bool compare(int a, int b) {
	return a > b;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		price.push_back(input);
	}

	sort(price.begin(), price.end(), compare);

	int cnt=2;

	for (int i = 0; i < n; i++) {
		if (cnt == 0) {
			cnt = 2;
		}
		else {
			sum += price[i];
			cnt--;
		}
	}

	cout << sum;


	return 0;
}