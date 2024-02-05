#include <iostream>

using namespace std;

const int dy[] = { -1,0,1,0 }; 
const int dx[] = { 0,-1,0,1 };

struct STUDENT
{
    int me;
    int fri[4];
    int y, x;
};

int N;
int board[20][20];
STUDENT st[400];

int getPoint(int y, int x, int s) {
    int point = 0;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        if (board[ny][nx] == 0) {
            point++;
        }
        else {
            for (int f = 0; f < 4; f++) {
                if (board[ny][nx] == st[s].fri[f]) {
                    point += 10;
                }
            }
        }
    }

    return point;
}

void setStudent(int y, int x, int s) {
    st[s].y = y, st[s].x = x;
    board[y][x] = st[s].me;
}

int calcPoint(int s) {
    int point = 0;
    int y = st[s].y;
    int x = st[s].x;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            continue;
        }
        for (int f = 0; f < 4; f++) {
            if (board[ny][nx] == st[s].fri[f]) {
                if (point == 0) {
                    point++;
                }
                else {
                    point *= 10;
                }
            }
        }
    }

    return point;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    //입력
    cin >> N;
    for (int i = 0; i < N * N; i++) {
        cin >> st[i].me >> st[i].fri[0] >> st[i].fri[1] >> st[i].fri[2] >> st[i].fri[3];
    }

    for (int i = 0; i < N * N; i++) {
        int candiy = -1, candix = -1, point = -1; //배치되는 임시공간 변수
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (board[y][x] == 0) {
                    int curPoint = getPoint(y, x, i);
                    if (point < curPoint) {
                        candiy = y, candix = x, point = curPoint;
                    }
                }
            }
        }
        setStudent(candiy, candix, i);

    }

    int ret = 0;
    for (int i = 0; i < N * N; i++) {
        ret += calcPoint(i);
    }

    cout << ret;

    return 0;
}