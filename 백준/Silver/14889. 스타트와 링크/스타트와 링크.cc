#include <iostream>

using namespace std;

int n, ret;
int table[20][20];
int team1[10], team2[10];
int pick[20];

void update() {
	int team1_size = 0, team2_size = 0;
	for (int i = 0; i < n; i++) {
		//안뽑혔으면
		if (pick[i] == 0) {
			team1[team1_size++] = i;
		}
		else {
			team2[team2_size++] = i;
		}
	}

	int sum_1 = 0, sum_2 = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = i+1; j < n / 2; j++) {
			sum_1 += (table[team1[i]][team1[j]] + table[team1[j]][team1[i]]);
			sum_2 += (table[team2[i]][team2[j]] + table[team2[j]][team2[i]]);
		}
	}
	if (ret > abs(sum_1 - sum_2)) {
		ret = abs(sum_1 - sum_2);
	}
}

void dfs(int cur, int pick_count) {
	//n의 절반을 뽑았으면 종료
	if (pick_count == (n / 2)) {
		update();
		return;
	}

	//경우의 수
	for (int i = cur; i < n; i++) {
		pick[i] = 1; //팀원 뽑기
		dfs(i + 1, pick_count + 1);
		pick[i] = 0; //백트래킹
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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