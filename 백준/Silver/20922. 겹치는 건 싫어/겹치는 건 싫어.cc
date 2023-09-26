#include <iostream>
#include<algorithm>

using namespace std;

int arr[200001];
int cnt[100001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	int ret = 0;
	int start = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
		//arr[i]를 수열에 포함시켰는데 arr[i]의 cnt가 k보다 큰 경우 start 증가
		//end는 항상 증가하기 때문에 i로 그냥 써도된다.
		while (cnt[arr[i]] > k) {
			cnt[arr[start++]]--;
		}
		ret = max(ret, i - start + 1);
	}

	cout << ret;


	return 0;
}