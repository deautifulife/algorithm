#include <iostream>

using namespace std;

int N, K;
int A[200];

int solve() {
	int ret = 0;
	int zero_count = 0;
	int robot[200 * 1000];
	int front = 0, back = 0;
	while (zero_count < K) {
		ret++;

		//벨트 움직임
		int temp = A[2 * N - 1]; //가장 마지막 값 복사
		//이전값을 현재값에 복사
		for (int i = 2 * N - 1; i >= 1; i--) {
			A[i] = A[i - 1];
		}
		A[0] = temp;
		
		//로봇 내림
		for (int i = front; i < back; i++) {
			robot[i]++;
			if (robot[i] == N - 1) {
				front++;
			}
		}

		//로봇이 움직임
		for (int i = front; i < back; i++) {
			int next = robot[i] + 1;
			if (A[next] == 0 || (i != front && robot[i-1] == next)) {
				continue;
			}
			robot[i] = next;
			if (next == N - 1) {
				front++;
			}
			A[next]--;
			if (A[next] == 0) {
				zero_count++;
			}
		}

		//로봇 올릴 수 있는지 체크
		if (A[0] > 0 && (back == 0 || robot[back - 1] != 0)) {
			robot[back++] = 0;
			A[0]--;
			if (A[0] == 0) {
				zero_count++;
			}
		}
	}

	return ret;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i * 2] >> A[i * 2 + 1];
	}
	int ret = solve();
	cout << ret;

	return 0;
}