#include <iostream>

using namespace std;

int n, m, r;
int board[301][301];
int temp[301][301];

void rotation() {
	//박스
	for (int rot = 0; rot < min(n, m) / 2; rot++) {
		int y1 = rot, x1 = rot, y2 = n - 1 - rot, x2 = m - 1 - rot;
		//top
		for (int i = x2 - 1; i >= x1; i--) {
			temp[y1][i] = board[y1][i + 1];
		}
		//left
		for (int i = y1 + 1; i <= y2; i++) {
			temp[i][x1] = board[i - 1][x1];
		}
		//bottom
		for (int i = x1 + 1; i <= x2; i++) {
			temp[y2][i] = board[y2][i - 1];
		}
		//right
		for (int i = y2 - 1; i >= y1; i--) {
			temp[i][x2] = board[i + 1][x2];
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			board[y][x] = temp[y][x];
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> board[y][x];
		}
	}

	while (r--) {
		rotation();
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}