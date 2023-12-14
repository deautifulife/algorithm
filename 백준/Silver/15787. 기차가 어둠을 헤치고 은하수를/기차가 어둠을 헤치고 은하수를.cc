#include <iostream>

using namespace std;
	
int N, M;
int seat[100001][21];
int ret;
int record[100001][21];

void run12(int com, int train, int order) {
	if (com == 1) {
		if (seat[train][order] == 0) {
			seat[train][order] = 1;
		}
	}
	else if (com == 2) {
		if (seat[train][order] == 1) {
			seat[train][order] = 0;
		}
	}
}

void run34(int com, int train) {
	if (com == 3) {
		int temp_seat[21];
		for (int i = 1; i <= 20; i++) {
			temp_seat[i] = seat[train][i]; //자리 복사
		}
		for (int i = 1; i < 20; i++) {
			seat[train][i + 1] = temp_seat[i]; //이동
		}
		seat[train][1] = 0;
	}
	else if (com == 4) {
		int temp_seat[21];
		for (int i = 1; i <= 20; i++) {
			temp_seat[i] = seat[train][i]; //자리 복사
		}
		for (int i = 2; i <= 20; i++) {
			seat[train][i - 1] = temp_seat[i]; //이동
		}
		seat[train][20] = 0;
	}
}

void check() {
	int save = 1;
	//1번째 기차는 통과
	ret++;
	for (int i = 1; i <= 20; i++) {
		record[1][i] = seat[1][i];
	}
	//2번째 기차부터 비교
	for (int i = 2; i <= N; i++) { //기차
		bool pass = false;
		for (int j = 1; j <= save; j++) { //기록
			int same = 0;
			for (int k = 1; k <= 20; k++) {
				if (record[j][k] == seat[i][k]) {
					same++;
				}
			}
			if (same == 20) {
				pass = false;
				break;
			}
			else
				pass = true;
		}
		if (pass) {
			ret++;
			save++;
			for (int k = 1; k <= 20; k++) {
				record[save][k] = seat[i][k];
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int com, train, order;
		cin >> com;
		if (com == 1 || com == 2) {
			cin>> train >> order;
			run12(com, train, order);
		}
		else if (com == 3 || com == 4) {
			cin >> train;
			run34(com, train);
		}
	}

	check();

	cout << ret;

	return 0;
}