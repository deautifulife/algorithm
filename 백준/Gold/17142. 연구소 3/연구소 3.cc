#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct POS {
	int y, x, time;
};

int n, m, ret;
int map[50][50];

int pos_size;
POS pos[10];

int bfs(int pick[]) {
	int empty_count = 0;//bfs가 끝나는 조건 : 빈 공간이 없다.
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 0) {
				empty_count++;
			}
		}
	}

	queue<POS> q;
	int visited[50][50] = { 0, };
	for (int i = 0; i < m; i++) {
		q.push(pos[pick[i]]);
		visited[pos[pick[i]].y][pos[pick[i]].x] = 1;
	}

	const int dy[] = { 1,-1,0,0 };
	const int dx[] = { 0,0,-1,1 };
	while (!q.empty()) {
		POS cur = q.front();
		q.pop();

		if (map[cur.y][cur.x] == 0) {
			empty_count--;
		}
		if (empty_count == 0) {
			return cur.time;
		}

		POS next;
		next.time = cur.time + 1;
		for (int d = 0; d < 4; d++) {
			next.y = cur.y + dy[d];
			next.x = cur.x + dx[d];
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) {
				continue;
			}
			if (visited[next.y][next.x] == 0 && map[next.y][next.x] != 1) {
				q.push(next);
				visited[next.y][next.x] = 1;
			}
		}
	}
	return 0x7fffffff;
}

void dfs(int last_pick, int pick_count, int pick[]) {
	if (pick_count == m) {
		int candi = bfs(pick);
		if (ret > candi) {
			ret = candi;
		}
		return;
	}

	for (int i = last_pick + 1; i < pos_size; i++) {
		pick[pick_count] = i;
		dfs(i, pick_count + 1, pick);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			//바이러스가 들어오면
			if (map[y][x] == 2) {
				pos[pos_size].y = y;
				pos[pos_size].x = x;
				pos[pos_size].time = 0;
				pos_size++;
			}
		}
	}
	ret = 0x7fffffff;
	int pick[10] = { 0, };
	dfs(-1, 0, pick); //마지막으로 뽑은 인덱스, 현재 몇개를 뽑았는지, 현재 누구를 뽑았는지
	if (ret == 0x7fffffff) {
		cout << -1 << '\n';
	}
	else {
		cout << ret;
	}
	

	return 0;
}