#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double arr[100001];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	double max=0;
	double ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == max)
			continue;
		ans += arr[i] / 2;
	}

	ans += max;
	cout << ans;

	return 0;
}