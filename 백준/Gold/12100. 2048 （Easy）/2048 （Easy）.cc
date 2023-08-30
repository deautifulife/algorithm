#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,ret;

struct BOARD {
	int map[20][20];

	//멤버함수
	void rotate() {
		int temp[20][20];

		//x,y를 바꿔서 90도 회전
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				temp[y][x] = map[n - x - 1][y]; //index가 0부터 시작하니 1을 빼주는 것
			}
		}

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				map[y][x] = temp[y][x];
			}
		}
	}

	int get_max() {
		int ret = 0;

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (ret < map[y][x]) {
					ret = map[y][x];
				}
			}
		}

		return ret;
	}

	//up 방향
	void up() {
		int temp[20][20];

		for (int x = 0; x < n; x++) {
			int flag = 0, target = -1;//이전에 갱신이있었는지 없었는지 플래그, temp에 복사하기 위해 타겟점을 포인팅하기 위한 변수
			for (int y = 0; y < n; y++) {
				if (map[y][x] == 0) {
					continue;
				}

				//한 번 값이 옮겨졌었고, 내가 지금 옮기려는 값과 지도에 옮겨져있는 값이 같으면
				if (flag == 1 && map[y][x] == temp[target][x]) {
					temp[target][x] *= 2, flag = 0;
				}
				else {
					temp[++target][x] = map[y][x], flag = 1;
				}
			}
			//target이 끝까지 안돌때 빈칸에 0을 채워넣음
			for (++target; target < n; ++target) {
				temp[target][x] = 0;
			}
		}
		
		//맵에 다시 옮기기
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				map[y][x] = temp[y][x];
			}
		}
	}
};

void dfs(BOARD cur, int count) {
	//5번이동했을 때 최대값
	if (count == 5) {
		int candi = cur.get_max();
		if (ret < candi) {
			ret = candi;
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		BOARD next = cur;
		next.up();
		dfs(next, count + 1);
		cur.rotate();
	}

}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	BOARD board;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> board.map[y][x];
		}
	}

	ret = 0;
	dfs(board, 0);
	cout << ret;


	return 0;
}