#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool visited[26][26];
int map[26][26];
vector<int> ret;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void BFS(int row, int col) {
    queue<pair<int,int>> q;
    q.push(make_pair(row,col));
    visited[row][col] = true;
    int cnt = 0;
    cnt++;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
                continue;
            }
            if (map[ny][nx] == 1 && visited[ny][nx] == false) {
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
                cnt++;
            }
        }
    }
    ret.push_back(cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int y = 0; y < n; y++) {
        string str;
        cin >> str;
        for (int x = 0; x < n; x++) {
            map[y][x] = str[x] - '0';
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (visited[y][x] == false && map[y][x] == 1) {
                BFS(y, x);
            }
        }
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }


}


