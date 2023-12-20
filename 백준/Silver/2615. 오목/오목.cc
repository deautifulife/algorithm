#include <iostream>

using namespace std;

int board[20][20];
int win;
int ry, rx;
bool stopcheck;
int in_a_row_black = 0;
int in_a_row_white = 0;

void check(int y, int x) {
	//가로 체크
	for (int dy = y; dy < y + 5; dy++) {
		in_a_row_black = 0;
		in_a_row_white = 0;
		for (int dx = x; dx < x + 5; dx++) {
			if (board[dy][dx] == 1) {
				in_a_row_black++;
				in_a_row_white = 0;
			}
			else if (board[dy][dx] == 2) {
				in_a_row_white++;
				in_a_row_black = 0;
			}
		}
		if (in_a_row_black == 5) {
			//육목 체크
			if(board[dy][x + 5] == 1 || board[dy][x-1] == 1) {
				win = 0;
				stopcheck = 0;
			}
			else {
				win = 1;
				ry = dy;
				rx = x;
				stopcheck = 1;
			}
		}
		else if (in_a_row_white == 5) {
			//육목 체크
			if (board[dy][x + 5] == 2 || board[dy][x - 1] == 2) {
				win = 0;
				stopcheck = 0;
			}
			else {
				win = 2;
				ry = dy;
				rx = x;
				stopcheck = 1;
			}
		}
	}
	//세로 체크
	for (int dx = x; dx < x + 5; dx++) {
		in_a_row_black = 0;
		in_a_row_white = 0;
		for (int dy = y; dy < y + 5; dy++) {
			if (board[dy][dx] == 1) {
				in_a_row_black++;
				in_a_row_white = 0;
			}
			else if (board[dy][dx] == 2) {
				in_a_row_white++;
				in_a_row_black = 0;
			}
		}
		if (in_a_row_black == 5) {
			//육목 체크
			if (board[y+5][dx] == 1 || board[y-1][dx] == 1) {
				win = 0;
				stopcheck = 0;
			}
			else {
				win = 1;
				ry = y;
				rx = dx;
				stopcheck = 1;
			}
		}
		else if (in_a_row_white == 5) {
			//육목 체크
			if (board[y + 5][dx] == 2 || board[y - 1][dx] == 2) {
				win = 0;
				stopcheck = 0;
			}
			else {
				win = 2;
				ry = y;
				rx = dx;
				stopcheck = 1;
			}
		}
	}
	//좌대각
	in_a_row_black = 0;
	in_a_row_white = 0;
	for (int i = 0; i < 5; i++) {
		if (board[y + i][x + i] == 1) {
			in_a_row_black++;
			in_a_row_white = 0;
		}
		else if (board[y + i][x + i] == 2) {
			in_a_row_white++;
			in_a_row_black = 0;
		}
	}
	if (in_a_row_black == 5) {
		//육목 체크
		if (board[y + 5][x + 5] == 1 || board[y-1][x-1] == 1) {
			win = 0;
			stopcheck = 0;
		}
		else {
			win = 1;
			ry = y;
			rx = x;
			stopcheck = 1;
		}
	}
	else if (in_a_row_white == 5) {
		//육목 체크
		if (board[y + 5][x + 5] == 2 || board[y - 1][x - 1] == 2) {
			win = 0;
			stopcheck = 0;
		}
		else {
			win = 2;
			ry = y;
			rx = x;
			stopcheck = 1;
		}
	}
	//우대각
	in_a_row_black = 0;
	in_a_row_white = 0;
	for (int i = 0; i < 5; i++) {
		if (board[y + i][x + 4 - i] == 1) {
			in_a_row_black++;
			in_a_row_white = 0;
		}
		else if (board[y + i][x + 4 - i] == 2) {
			in_a_row_white++;
			in_a_row_black = 0;
		}
	}
	if (in_a_row_black == 5) {
		//육목 체크
		if (board[y + 5][x - 1] == 1 || board[y-1][x+5] == 1) {
			win = 0;
			stopcheck = 0;
		}
		else {
			win = 1;
			ry = y + 4;
			rx = x;
			stopcheck = 1;
		}
	}
	else if (in_a_row_white == 5) {
		//육목 체크
		if (board[y + 5][x - 1] == 2 || board[y - 1][x + 5] == 2) {
			win = 0;
			stopcheck = 0;
		}
		else {
			win = 2;
			ry = y + 4;
			rx = x;
			stopcheck = 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int y = 1; y <= 19; y++) {
		for (int x = 1; x <= 19; x++) {
			cin >> board[y][x];
		}
	}

	//검사
	for (int y = 1; y <= 15; y++) {
		for (int x = 1; x <= 15; x++) {
			check(y,x);
			if (stopcheck == 1) {
				cout << win<<'\n';
				if (win == 1 || win == 2) {
					cout << ry << " "<<rx;
				}
				return 0;
			}
		}
	}

	cout << "0";

	return 0;
}