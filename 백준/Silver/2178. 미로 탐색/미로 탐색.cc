#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[101][101];
bool visited[101][101];
int dist[101][101];
int n, m;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

// 큐
void BFS(int row, int col) {
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    visited[row][col] = 1;
    dist[row][col]++;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            if (visited[ny][nx] == 0 && map[ny][nx] == 1) {
                q.push(make_pair(ny, nx));
                visited[ny][nx] = 1;
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
        string row;
        cin >> row;
        for (int x = 0; x < m; x++) {
            map[y][x] = row[x] - '0';
        }
    }

    BFS(0, 0);

    cout << dist[n-1][m-1];
}