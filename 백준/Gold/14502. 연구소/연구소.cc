#include <iostream>
#include <queue>
#include<algorithm>

using namespace std;

int n, m;
int map[8][8];
int ret;

const int dy[] = { -1, 1, 0 ,0 };
const int dx[] = { 0, 0, -1, 1 };

//가스 확산 후 안전한 지역 확인
void bfs() {
	queue<int> q;
	
	//오리지널 맵 백업
	int backup[8][8];
	int visited[8][8] = { 0, };
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			backup[y][x] = map[y][x];
			//유해가스가 있으면
			if (backup[y][x] == 2) {
				q.push(y * 10 + x); //q에 유해가스 위치 저장 yx로 표현하기 위한 식
				visited[y][x] = 1;
			}
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int cy = cur / 10;
		int cx = cur % 10;

		backup[cy][cx] = 2;

		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				continue;
			}
			if (visited[ny][nx] == 0 && backup[ny][nx] == 0) {
				visited[ny][nx] = 1;
				q.push(ny * 10 + nx);
			}
		}
	}

	int candi = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (backup[y][x] == 0) {
				candi++;
			}
		}
	}
	if (ret < candi) {
		ret = candi;
	}
}

//벽 세우는 경우의 수 진행
void pick_dfs(int count, int sy, int sx) {
	if (count == 3) {
		//TODO something...
		bfs();
		return;
	}

	for (int y = sy; y < n; y++) {
		for (int x = sx; x < m; x++) {
			//빈 공간이면
			if (map[y][x] == 0) {
				map[y][x] = 1;
				pick_dfs(count + 1, y, x);
				map[y][x] = 0; //백트래킹 방식으로 여기 다시 0을 넣어준다.
			}
		}
		sx = 0; //다음 y좌표부터는 x가 0부터 시작되어야 하므로
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
		}
	}

	//벽을 세우는 경우의 수
	pick_dfs(0, 0, 0); //추가한 벽 수, 좌표

	cout << ret;

	return 0;
}