#include <iostream>

using namespace std;

int n, ret;
int table[20][20];
int team1[20], team2[20];
int pick[20];

void update() {
	int team1_score = 0;
	int team2_score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pick[i] && pick[j]) {
				team1_score += table[i][j];
			}
			if (!pick[i] && !pick[j]) {
				team2_score += table[i][j];
			}
		}
	}

	if (ret > abs(team1_score - team2_score)) {
		ret = abs(team1_score - team2_score);
	}
}

void dfs(int cur, int pick_count) {
	//n의 절반을 뽑았으면 종료
	if (pick_count >= 1 && pick_count <= (n / 2)) {
		update();
	}

	//경우의 수
	for (int i = cur; i < n; i++) {
		pick[i] = 1; //팀원 뽑기
		dfs(i + 1, pick_count + 1);
		pick[i] = 0; //백트래킹
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> table[y][x];
		}
	}

	ret = 0x7fffffff;
	dfs(0, 0);
	cout << ret;

	return 0;
}