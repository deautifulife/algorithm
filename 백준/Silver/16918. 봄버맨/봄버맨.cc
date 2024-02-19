#include <iostream>
#include <queue>

using namespace std;

int R, C, N;
char map[201][201];

const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };

int main() {

    cin >> R >> C >> N;
    for (int y = 1; y <= R; y++) {
        for (int x = 1; x <= C; x++) {
            cin >> map[y][x];
        }
    }

    if (N % 2 == 0) {
        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                cout << "O";
            }
            cout << '\n';
        }
        return 0;
    }
    else {
        int cnt = 1;
        while (cnt < N) {
            queue<pair<int, int>> q;
            for (int y = 1; y <= R; y++) {
                for (int x = 1; x <= C; x++) {
                    if (map[y][x] == 'O')
                        q.push(make_pair(y, x));
                }
            }
            for (int y = 1; y <= R; y++) {
                for (int x = 1; x <= C; x++) {
                    map[y][x] = 'O';
                }
            }

            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (ny<1 || ny > R || nx<1 || nx>C)
                        continue;
                    map[ny][nx] = '.';
                }
                map[y][x] = '.';
            }
            cnt += 2;
        }
    }

    for (int y = 1; y <= R; y++) {
        for (int x = 1; x <= C; x++) {
            cout << map[y][x];
        }
        cout << '\n';
    }

    return 0;
}