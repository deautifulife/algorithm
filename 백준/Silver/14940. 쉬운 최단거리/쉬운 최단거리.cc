#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>


using namespace std;

const int dy[] = {0,-1,0,1};
const int dx[] = {-1,0,1,0};

struct GOAL {
	int gy;
	int gx;
};

GOAL goal;

int n, m;
int map[1001][1001];
int ret[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];

void BFS(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();


		for (int d = 0; d < 4; d++) {
			int ny = cy + dy[d];
			int nx = cx + dx[d];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (map[ny][nx] == 1 && visited[ny][nx] == false) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
				dist[ny][nx] = dist[cy][cx] + 1;
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2) {
				goal.gy = y;
				goal.gx = x;
			}
		}
	}

	BFS(goal.gy, goal.gx);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (map[y][x] != 0 && visited[y][x] == false)
				dist[y][x] = -1;
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cout << dist[y][x] << " ";
		}
		cout << '\n';
	}

	return 0;
}