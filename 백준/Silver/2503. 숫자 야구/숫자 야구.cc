#include <iostream>
#include <vector>

using namespace std;

int n;
int testcase[100][3];
vector<pair<int, int>> sb;
int num[999][2]; //2차원 숫자, 가능성

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	//모든 숫자 조합 생성
	int cnt = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (i == j || i == k || j == k)
					continue;

				num[cnt][0] = (i * 100 + j * 10 + k);
				cnt++;
			}
		}
	}

	//테스트 케이스 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> testcase[i][0]>> testcase[i][1]>> testcase[i][2];
	}

	//계산
	for (int i = 0; i < n; i++) {
		int t1 = testcase[i][0] / 100;
		int t2 = (testcase[i][0] / 10) % 10;
		int t3 = testcase[i][0] % 10;

		for (int j = 0; j < cnt; j++) {
			if (num[j][1] == 1)
				continue;

			int v1 = num[j][0] / 100;
			int v2 = (num[j][0] / 10) % 10;
			int v3 = num[j][0] % 10;

			int strike = 0, ball = 0;

			//strike
			if (t1 == v1) strike++;
			if(t2 == v2) strike++;
			if(t3 == v3) strike++;

			//ball
			if (v1 != t1 && (v1 == t2 || v1 == t3))
				ball++;
			if (v2 != t2 && (v2 == t1 || v2 == t3))
				ball++;
			if (v3 != t3 && (v3 == t1 || v3 == t2))
				ball++;

			if (!(strike == testcase[i][1] && ball == testcase[i][2]))
				num[j][1] = 1;
		}
	}

	int ret = 0;
	for (int i = 0; i < cnt; i++) {
		if (num[i][1] == 0)
			ret++;
	}

	cout << ret;


	return 0;
}