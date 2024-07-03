#include <iostream>
#include <vector>

using namespace std;

struct FIREBALL {
    int y, x;
    int m, s, d;
};

const int dy[8] = { -1,-1,0,1,1,1,0,-1 };
const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int N, M, K; //맵 크기, 파이어볼 갯수, 이동 수
vector<FIREBALL> ball;
vector<int> map[50][50];

void move() {
    vector<int> new_map[50][50]; //갱신을 위한 맵
    //볼의 사이즈 만큼 반복
    for (int i = 0; i < ball.size(); i++) {
        int dir = ball[i].d;
        int speed = (ball[i].s % N); //캡의 최대크기는 50인데 스피드는 최대 1000이므로 맵 크기만큼 모듈러 연산
        int ny = (ball[i].y + (dy[dir] * speed) + N) % N; //음수 방지로 +N 한후 %N
        int nx = (ball[i].x + (dx[dir] * speed) + N) % N;

        //볼 위치를 갱신
        new_map[ny][nx].push_back(i);
        ball[i].y = ny;
        ball[i].x = nx;
    }

    //갱신한 맵을 다시 원래의 맵으로 복사
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
            //볼 없음 무시
            if (map[y][x].size() == 0) {
                continue;
            }
            //볼 1개면 그냥 복사
            if (map[y][x].size() == 1) {
                int index = map[y][x][0];
                new_ball.push_back(ball[index]);
                continue;
            }

            //여기까지 코드가 내려왔으면 좌표에 볼이 2개이상인 경우
            int sum_m = 0, sum_s = 0; //질량합, 스피드합
            bool odd = true, even = true; //합쳐지는 파이어볼의 각 방향이 홀수인지 짝수인지 확인하기 위한 변수
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

            //합쳐진 파이어볼의 질량은 5로 나눈다.
            //0으로 나누어 떨어지면 질량이 없으므로 스피드, 방향 고려할 필요없이 사라진다. 고로 continue
            if (sum_m / 5 == 0) {
                continue;
            }
            int cur_m = sum_m / 5;

            //스피드는 스피드합 / 합쳐진 볼의 수
            int cur_s = sum_s / map[y][x].size();
            //4방향으로 쪼개기
            for (int i = 0; i < 4; i++) {
                //모두 짝수거나 홀수거나
                if (odd || even) {
                    new_ball.push_back({ y,x,cur_m,cur_s, i * 2 }); //0,2,4,6이므로 i*2
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
    //남아있는 파이어볼의 갯수만큼 반복
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
        y--, x--; //문제에서 입력좌표가 1부터 시작하므로 -1씩 해준다.
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