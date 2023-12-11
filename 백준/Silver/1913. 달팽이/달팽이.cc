#include <iostream>

using namespace std;

int N;
int num;
int board[999][999];
int dy[4] = {-1,0,1,0};
int dx[4] = { 0,1,0,-1 };

int turn = 0;
int cnt = 0; //같은 방향 이동 횟수
int maxd = 1; //최대 이동 횟수
int turncnt = 0; //방향 전환 횟수
int retX,retY;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	cin >> N;
	cin >> num;
	int curY = N / 2;
	int curX = N / 2;
	for(int i=1; i<=N*N; i++){
		board[curY][curX] = i;
		if (i == num) {
			retY = curY + 1;
			retX = curX + 1;
		}

		//현재 방향으로 위치 한칸 이동
		curY += dy[turn % 4];
		curX += dx[turn % 4];
		cnt++;

		//방향전환
		if (cnt == maxd) {
			turn++;
			cnt = 0;
			turncnt++;
		}

		//방향전환 2번할 때마다 최대 이동횟수 ++
		if (turncnt == 2) {
			maxd++;
			turncnt = 0;
		}

		
	}
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << board[y][x] << ' ';
			if (x == N-1)
				cout << '\n';
		}
	}
	cout << retY << ' ' << retX;

	return 0;
}