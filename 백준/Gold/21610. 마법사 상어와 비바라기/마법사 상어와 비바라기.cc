#include <iostream>
#include <cstring>

using namespace std;

const int dy[] = { 0,-1,-1,-1,0,1,1,1 };
const int dx[] = { -1,-1,0,1,1,1,0,-1 };

struct CLOUD {
    int y, x;
};

int N, M;
int cloud_size;
CLOUD cloud[2500];
int cloud_map[50][50];
int water[50][50];

void create_cloud(int y, int x) {
    cloud[cloud_size].y = y;
    cloud[cloud_size].x = x;
    cloud_size++;
}

void init_cloud() {
    create_cloud(N - 2, 0);
    create_cloud(N - 2, 1);
    create_cloud(N - 1, 0);
    create_cloud(N - 1, 1);
}
void move_cloud(int d, int s) {
    int dist_y = (dy[d] * s) + (N * 50); //항상 양수를 만들기위한 트릭이 뒤에 +로
    int dist_x = (dx[d] * s) + (N * 50);
    for (int i = 0; i < cloud_size; i++) {
        cloud[i].y = (dist_y + cloud[i].y) % N;
        cloud[i].x = (dist_x + cloud[i].x) % N;
    }
}
void increase_water() {
    for (int i = 0; i < cloud_size; i++) {
        water[cloud[i].y][cloud[i].x]++;
    }
}
void delete_cloud() {
    memset(cloud_map, 0, sizeof(cloud_map));
    for (int i = 0; i < cloud_size; i++) {
        cloud_map[cloud[i].y][cloud[i].x] = 1;
    }
    cloud_size = 0;
}
void copy_bug() {
    int increase_water[50][50] = { 0, };
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (cloud_map[y][x] == 1) {
                int cnt = 0;
                for (int d = 1; d < 8; d += 2) { //대각선만 돌기위해 d+=2
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
                        continue;
                    }
                    if (water[ny][nx] >= 1) {
                        cnt++;
                    }
                }
                increase_water[y][x] += cnt;
            }
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            water[y][x] += increase_water[y][x];
        }
    }
}
void generate_cloud() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (water[y][x] >= 2 && cloud_map[y][x] == 0) {
                create_cloud(y, x);
                water[y][x] -= 2;
            }
        }
    }
}

int main() {

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> water[y][x];
        }
    }

    init_cloud();
    for (int i = 0; i < M; i++) {
        int d, s;
        cin >> d >> s;
        move_cloud(d - 1, s); //index가 0부터 이므로
        increase_water();
        delete_cloud();
        copy_bug();
        generate_cloud();
    }

    int ret = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            ret += water[y][x];
        }
    }

    cout << ret;

    return 0;
}