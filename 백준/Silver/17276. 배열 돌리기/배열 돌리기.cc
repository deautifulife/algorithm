#include <iostream>

using namespace std;
	
int T;
int N;
int d;
int board[501][501];
int afterboard[501][501];

void turnright() {
	//일단 그대로 복사
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			afterboard[y][x] = board[y][x];
		}
	}
	//수정
	for (int i = 1; i <= N; i++) {
		afterboard[i][(N + 1) / 2] = board[i][i]; //주 대각선을 가운데 열로 복사
		afterboard[i][N+1 - i] = board[i][(N + 1) / 2]; //가운데 열을 부 대각선으로 복사
		afterboard[(N+1)/2][N+1-i] = board[i][N+1 - i]; //부 대각선을 가운데 행으로 복사
		afterboard[i][i] = board[(N + 1) / 2][i]; //가운데 행을 주 대각선으로 복사
	}

	//다시 동작을 위한 afterboard를 board로 저장
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			board[y][x] = afterboard[y][x];
		}
	}

}

void turnleft() {
	//일단 복사
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			afterboard[y][x] = board[y][x];
		}
	}
	//수정
	for (int i = 1; i <= N; i++) {
		afterboard[(N + 1) / 2][i] = board[i][i]; //주 대각선을 가운데 행으로 복사
		afterboard[i][i] = board[i][(N + 1) / 2]; //가운데 열을 주 대각선으로 복사
		afterboard[i][(N + 1) / 2] = board[i][N+1 - i]; //부 대각선을 가운데 열로
		afterboard[N+1 - i][i] = board[(N + 1) / 2][i]; //가운데 행을 부 대각선으로 
	}

	//다시 동작을 위한 afterboard를 board로 저장
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			board[y][x] = afterboard[y][x];
		}
	}

}


int main() {

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> d;
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				cin >> board[y][x];
			}
		}

		while (d != 0) {
			if (d > 0) {
				turnright();
				d -= 45;
			}
			else if (d < 0) {
				turnleft();
				d += 45;
			}
		}

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				cout<<board[y][x]<<" ";
			}
			cout << '\n';
		}
	}

	return 0;
}