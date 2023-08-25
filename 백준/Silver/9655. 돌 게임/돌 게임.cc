#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int DP[1001];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= n; i++) {
		DP[i] = min(DP[i - 1] + 1, DP[i - 3] + 1);

	}
	
	if (DP[n] % 2 == 1) 
		cout << "SK";
	else
		cout << "CY";

	return 0;
}