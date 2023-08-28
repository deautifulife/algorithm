#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char arr[400][400];

void draw(int len, int row, int col) {
	for (int i = 0; i < len; i++) {
		if (i == 0 || i == len - 1) //윗변, 아랫변{
			for (int j = 0; j < len; j++) {
				arr[row + i][col + j] = '*';
			}
		else {//높이 : 별 2개만 찍기
			arr[row + i][col] = '*'; //첫번째 열
			arr[row + i][col + len - 1] = '*'; //마지막 열
		}
	}
}

void square(int n, int row, int col) {
	int len = 4 * n - 3;
	draw(len, row, col); //재귀 전에 현재 지점의 사각형 먼저 그리기

	if (n == 1)
		return;
	square(n - 1, row + 2, col + 2); //다음 사각형으로 재귀시 다음 재귀 시작 지점 인수로 넘겨주기
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	//별찍기 전에 미리 전체 배열에 공백 넣기
	for (int i = 0; i < 4 * n - 3; i++) {
		for (int j = 0; j < 4 * n - 3; j++) {
			arr[i][j] = ' ';
		}
	}
	
	square(n, 0, 0); //별 찍기

	for (int i = 0; i < 4 * n - 3; i++) {
		for (int j = 0; j < 4 * n - 3; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}