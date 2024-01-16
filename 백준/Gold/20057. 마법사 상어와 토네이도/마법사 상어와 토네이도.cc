#include <iostream>


using namespace std;

int N;
int A[499][499];

//left down right up
int dy[] = { 0,1,0,-1 };
int dx[] = { -1,0,1,0 };
int windy[4][9] = {
    {-1,1,-2,2,0,-1,1,-1,1}, //left
    {-1,-1,0,0,2,0,0,1,1}, // down
    {1,-1,2,-2,0,1,-1,1,-1}, //right
    {1,1,0,0,-2,0,0,-1,-1} //up
};

int windx[4][9] = {
    {1,1,0,0,-2,0,0,-1,-1}, //left
    {-1,1,-2,2,0,-1,1,-1,1}, // down
    {-1,-1,0,0,2,0,0,1,1}, //right
    {1,-1,2,-2,0,1,-1,1,-1} //up
};

int rate[9] = { 1,1,2,2,5,7,7,10,10 };

int wind(int cy, int cx, int dir) {
    int ret = 0;
    int sand = A[cy][cx];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int ny = cy + windy[dir][i];
        int nx = cx + windx[dir][i];
        int wind_sand = (sand * rate[i]) / 100;
        sum += wind_sand;
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            ret += wind_sand;
            continue;
        }
        A[ny][nx] += wind_sand;
    }

    //알파 위치는 y에서 한칸 더 가면 됨
    int ny = cy + dy[dir];
    int nx = cx + dx[dir];
    int a = (sand - sum);
    if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
        ret += a;
    }
    else {
        A[ny][nx] += a;
    }
    A[cy][cx] = 0;

    return ret;
}

int solve(int cy, int cx) {
    int ret = 0;
    bool visited[499][499] = { false, };
    int dir = -1;
    while ((cy != 0) || (cx != 0)) {
        visited[cy][cx] = true;
        int nd = (dir + 1) % 4;
        int ny = cy + dy[nd];
        int nx = cx + dx[nd];
        if (visited[ny][nx] == true) { //방문한 곳이면 회전없이 같은 방향으로 쭉 한번 더 감
            nd = dir;
            ny = cy + dy[nd];
            nx = cx + dx[nd];
        }
        ret += wind(ny, nx, nd);
        cy = ny, cx = nx, dir = nd;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> A[y][x];
        }
    }

    int cy = N / 2;
    int cx = N / 2;
    int ret = solve(cy, cx);
    cout << ret;

}


