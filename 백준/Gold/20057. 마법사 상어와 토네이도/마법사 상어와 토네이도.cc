#include <iostream>


using namespace std;

int N;
int A[499][499];

//left down right up
int dy[] = { 0,1,0,-1 };
int dx[] = { -1,0,1,0 };

//바람의 이동방향에 따른 모래의 이동 비율
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

//위 방향대로 이동했을 때 모래의 이동비율
int rate[9] = { 1,1,2,2,5,7,7,10,10 };

int wind(int cy, int cx, int dir) {
    int ret = 0;
    int sand = A[cy][cx];
    int sum = 0;
    //9방향 돌면서 모래 이동
    for (int i = 0; i < 9; i++) {
        int ny = cy + windy[dir][i];
        int nx = cx + windx[dir][i];
        int wind_sand = (sand * rate[i]) / 100;
        sum += wind_sand;
        //맵 밖으로 나간 경우는 그냥 모래만 빠져나간 처리
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            ret += wind_sand;
            continue;
        }
        //원래 있던 모래에 더해주기
        A[ny][nx] += wind_sand;
    }

    //알파위치 모래 구하기
    //알파 위치는 y에서 한칸 더 가면 됨
    int ny = cy + dy[dir];
    int nx = cx + dx[dir];
    int a = (sand - sum);
    //맵 빠져 나가면
    if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
        ret += a;
    }
    else {
        A[ny][nx] += a;
    }
    
    //현재 위치의 모래는 없어진다.
    A[cy][cx] = 0;

    return ret;
}

int solve(int cy, int cx) {
    int ret = 0;
    bool visited[499][499] = { false, };
    int dir = -1;
    
    //0,0(토네이도마지막 지점)까지 이동
    while ((cy != 0) || (cx != 0)) {
        visited[cy][cx] = true;
        int nd = (dir + 1) % 4;
        int ny = cy + dy[nd];
        int nx = cx + dx[nd];
        if (visited[ny][nx] == true) { //이미 방문한 곳이면 회전없이 같은 방향으로 쭉 한번 더 감
            //이전 방향으로 다시
            nd = dir; 
            ny = cy + dy[nd];
            nx = cx + dx[nd];
        }
        //맵에서 밖으로 나간 모래의 양을 합산
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
    //모래의 양 입력
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> A[y][x];
        }
    }

    //토네이도 시작 위치(맵의 중앙위치)
    int cy = N / 2;
    int cx = N / 2;

    int ret = solve(cy, cx);
    cout << ret;

}