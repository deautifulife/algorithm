#include <iostream>
#include <vector>

using namespace std;

struct FIREBALL {
    int y, x;
    int m, s, d;
};

const int dy[8] = {-1,-1,0,1,1,1,0,-1};
const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int N, M, K;
vector<FIREBALL> ball;
vector<int> map[50][50];

void move() {
    vector<int> new_map[50][50]; //갱신을 위한 맵
    for (int i = 0; i < ball.size(); i++) {
        int dir = ball[i].d;
        int speed = (ball[i].s % N); //캡의 크기는 50이니까 
        int ny = (ball[i].y + (dy[dir] * speed) + N) % N;
        int nx = (ball[i].x + (dx[dir] * speed) + N) % N;
        new_map[ny][nx].push_back(i);
        ball[i].y = ny;
        ball[i].x = nx;
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            map[y][x] = new_map[y][x];
        }
    }

}

void sum() {
    vector<FIREBALL> new_ball;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x].size() == 0) {
                continue;
            }
            if (map[y][x].size() == 1) {
                int index = map[y][x][0];
                new_ball.push_back(ball[index]);
                continue;
            }
            int sum_m = 0, sum_s = 0;
            bool odd = true, even = true;
            for (int i = 0; i < map[y][x].size(); i++) {
                int index = map[y][x][i];
                sum_m += ball[index].m;
                sum_s += ball[index].s;
                if (ball[index].d % 2 == 0) {
                    odd = false;
                }
                else {
                    even = false;
                }
            }

            if (sum_m / 5 == 0) {
                continue;
            }
            int cur_m = sum_m / 5;
            int cur_s = sum_s / map[y][x].size();
            for (int i = 0; i < 4; i++) {
                if (odd || even) {
                    new_ball.push_back({ y,x,cur_m,cur_s,i * 2 });
                }
                else {
                    new_ball.push_back({ y,x,cur_m,cur_s,i * 2 + 1 });
                }
            }
        }
    }

    ball = new_ball;
}

int solve() {
    while (K--) {
        move();
        sum();
    }
    int ret = 0;
    for (int i = 0; i < ball.size(); i++) {
        ret += ball[i].m; //볼의 질량 합
    }
    return ret;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int y, x, m, s, d;
        cin >> y >> x >> m >> s >> d;
        y--, x--; //입력좌표가 1부터이므로
        ball.push_back({ y,x,m,s,d });
        map[y][x].push_back(i); //ball의 위치값을 저장 
    }
    int ret = solve();
    cout << ret;

}

/*
1. 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
        이동하는 중에는 같은 칸에 여러 개의 파이어볼이 있을 수도 있다.
2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
    1. 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
    2. 파이어볼은 4개의 파이어볼로 나누어진다.
    3. 나누어진 파이어볼의 질량, 속력, 방향은 다음과 같다.
        1.질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
        2.속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
        3.합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
    4. 질량이 0인 파이어볼은 소멸되어 없어진다.
*/