#include <iostream>

using namespace std;

int board[10][10];
bool visited[10][10];
int n;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int ret = 99999999;

void resetDir(int r, int c) {
	visited[r][c] = false;

	for (int i = 0; i < 4; i++) {
		int nR = r + dy[i];
		int nC = c + dx[i];
		visited[nR][nC] = false;
	}
}

int sumDir(int r, int c) {
	//꽃이 죽는 경우는 visited를 건들지 않음
	for (int i = 0; i < 4; i++) {
		int nR = r + dy[i];
		int nC = c + dx[i];
		if (visited[nR][nC]) {
			return -1;
		}
	}
	//꽃이 죽지 않는 경우 visited를 1로 만들고 sum을 리턴
	int sum = board[r][c];
	for (int i = 0; i < 4; i++) {
		int nR = r + dy[i];
		int nC = c + dx[i];
		visited[nR][nC] = true;
		sum += board[nR][nC];
	}
	return sum;
}

void dfs(int r, int c, int cnt, int cost) {
	if (cnt == 3) {
		ret = min(ret, cost);
		return;
	}
	for (int i = r; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (visited[i][j])
				continue;
			int sum = sumDir(i, j);
			//꽃이 죽지 않으면 다음 꽃 찾기
			if (sum != -1) {
				dfs(i, j, cnt + 1, cost + sum);
				resetDir(i, j); //백트래킹
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> board[y][x];
		}
	}

	for (int y = 1; y < n-1; y++) {
		for (int x = 1; x < n-1; x++) {
			int sum = sumDir(y, x);
			dfs(y, x, 1, sum);
			resetDir(y, x);
		}
	}
	cout << ret;

	return 0;
}

