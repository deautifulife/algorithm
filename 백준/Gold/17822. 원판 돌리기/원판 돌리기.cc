#include <iostream>


using namespace std;

const int DEL = -1;
int N, M, T;
int board[50][50];

void solve(int x, int d, int k) {
	int pick = x - 1; //index가 0부터이므로
	if (d == 1) {
		k = -k; //반시계
	}
	while (pick < N) {
		int temp[50] = { 0, };
		for (int i = 0; i < M; i++) {
			temp[(i + k + M) % M] = board[pick][i]; //회전된 값을 넣기
		}

		for (int i = 0; i < M; i++) {
			board[pick][i] = temp[i];
		}
		pick += x;
	}

	bool is_update = false;
	const int dy[4] = { -1,1,0,0 };
	const int dx[4] = { 0,0,-1,1 };
	bool check[50][50] = { false, };

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			for (int d = 0; d < 4; d++) {
				int ny = y + dy[d];
				int nx = (x + dx[d] + M) % M; //원판은 시작점과 끝점도 인접한다.
				if (ny < 0 || ny >= N) {
					continue;
				}
				if (board[y][x] != DEL && board[ny][nx] != DEL && board[y][x] == board[ny][nx]) {
					is_update = true;
					check[y][x] = true;
					check[ny][nx] = true;
				}
			}
		}
	}

	if (is_update) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (check[y][x]) {
					board[y][x] = DEL;
				}
			}
		}
	}

	else {
		int sum = 0, count = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (board[y][x] != DEL) {
					sum += board[y][x];
					count++;
				}
			}
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (board[y][x] != DEL) {
					if (board[y][x] *count > sum) {
						--board[y][x];
					}
					else if (board[y][x] *count< sum) {
						board[y][x]++;
					}
				}
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}

	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		solve(x,d,k);
	}

	int ret = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x] != DEL) {
				ret += board[y][x];
			}
		}
	}
	cout << ret;

}