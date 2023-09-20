#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int arr[50001];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = 0, end = 0;
	int cnt = 0; //홀수를 지운 카운트
	int ret = 0;

	while (1) {
		//구간 안에 홀수가 k 초과일 때
		if (cnt > k) {
			//start가 홀수면 cnt -1 -> start+1
			if (arr[start] % 2 == 1) {
				cnt -= 1;
			}
			start += 1;
		}
		else if (end == n) {
			break;
		}
		//end가 홀수면 cnt+1 -> end +1
		else {
			if (arr[end] % 2 == 1) {
				cnt += 1;
			}
			end += 1;
		}
		//구간 안에 홀수가 k개 이하라면 tail을 증가시켜 구간을 늘린다.
		if (cnt <= k) {
			ret = max(ret, end - start - cnt);
		}
	}
	cout << ret;

	return 0;
}