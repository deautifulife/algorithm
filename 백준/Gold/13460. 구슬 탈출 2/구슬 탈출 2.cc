#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO {
	int ry, rx, by, bx, count;
};

INFO start;
char map[10][11];

int bfs() {
	const int dy[] = { -1,1,0,0 };
	const int dx[] = { 0,0,-1,1 };
	int visited[10][10][10][10] = { 0, }; //ry,rx,by,bx
	queue<INFO> q;
	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = 1;

	int ret = -1;
	while (!q.empty()) {
		INFO cur = q.front();
		q.pop();
		if (cur.count > 10) break;
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
			ret = cur.count;
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			int next_ry = cur.ry;
			int next_rx = cur.rx;
			int next_by = cur.by;
			int next_bx = cur.bx;

			//빨간공 벽만날때까지 이동
			while (1) {
				if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {
					next_ry += dy[dir];
					next_rx += dx[dir];
				}
				else {
					if (map[next_ry][next_rx] == '#') {
						next_ry -= dy[dir];
						next_rx -= dx[dir];
					}
					break;
				}
			}
			//파란공 벽만날때까지 이동
			while (1) {
				if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {
					next_by += dy[dir];
					next_bx += dx[dir];
				}
				else {
					if (map[next_by][next_bx] == '#') {
						next_by -= dy[dir];
						next_bx -= dx[dir];
					}
					break;
				}
			}

			//둘이 같은 자리면
			if (next_ry == next_by && next_rx == next_bx) {
				//나가는 구멍이 아니면
				if (map[next_ry][next_rx] != 'O') {
					int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
					int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
					if (red_dist > blue_dist) {
						next_ry -= dy[dir];
						next_rx -= dx[dir];
					}
					else {
						next_by -= dy[dir];
						next_bx -= dx[dir];
					}
				}
			}
			if (visited[next_ry][next_rx][next_by][next_bx] == 0) {
				visited[next_ry][next_rx][next_by][next_bx] = 1;
				INFO next;
				next.ry = next_ry;
				next.rx = next_rx;
				next.by = next_by;
				next.bx = next_bx;
				next.count = cur.count + 1;
				q.push(next);
			}
		}
	}
	return ret;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'R') {
				start.ry = i;
				start.rx = j;
			}
			if (map[i][j] == 'B') {
				start.by = i;
				start.bx = j;
			}
		}
	}
	start.count = 0;

	int ret = bfs();
	cout << ret;


	return 0;
}