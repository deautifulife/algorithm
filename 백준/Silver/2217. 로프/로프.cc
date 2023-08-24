#include <iostream>
//#include <vector>
//#include <cmath>
#include <algorithm>
#include <functional>


using namespace std;

int rope[100001];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}

	sort(rope, rope + n, greater<int>());
	
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long sum =  rope[i] * (i+1); //i는 0부터니까
		if (sum > ans)
			ans = sum;
	}

	cout << ans;

	return 0;
}