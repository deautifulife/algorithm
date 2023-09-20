#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int arr[50001];
int d[50001][101]; //수열의 인덱스,K의 횟수

int DP(int x, int count, int length) {
	if (x <= 0 || count > k)
		return length;
	if (d[x][count] != 0)
		return d[x][count];

	int value = 0;
	//짝수면 length +1, 삭제 x
	if (arr[x] % 2 == 0)
		value = DP(x - 1, count, length + 1);
	//홀수이면서 count < K, 삭제
	else if (count < k)
		value = DP(x - 1, count + 1, length);
	else if (count == k)
		return length;
	return d[x][count] = value;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int ret = 0;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < k; j++) {
			if (arr[i] % 2 == 0)
				ret = max(ret, DP(i, j, 0));
		}
	}

	cout << ret;

	return 0;
}