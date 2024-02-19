#include <iostream>

using namespace std;

const int dy[] = { -1, 1, 0,0 };
const int dx[] = { 0, 0, -1, 1 };

int N, M, ret;
int line_size;
int line[2500];
int mat[49][49];

void destroy_by_rule(int d, int s) {
    int cy = N / 2;
    int cx = N / 2;
    for (int i = 1; i <= s; i++) {
        int ny = cy + (dy[d] * i);
        int nx = cx + (dx[d] * i);
        mat[ny][nx] = 0;
    }
}

void convert_to_line() {
    int ddy[] = { 0,1,0,-1 };
    int ddx[] = { -1,0,1,0 };
    line_size = 0;
    int cy = N / 2;
    int cx = N / 2;
    int d = 0;
    int loop_count = 2;
    for (int dist = 1; dist < N; dist++) {
        if (dist == N - 1) {
            loop_count = 3;
        }
        for (int i = 0; i < loop_count; i++) {
            for (int j = 0; j < dist; j++) {
                cy += ddy[d];
                cx += ddx[d];
                if (mat[cy][cx] != 0) {
                    line[line_size++] = mat[cy][cx];
                }
            }
            d = (d + 1) % 4;
        }
    }
}

int destroy_by_rule() {
    int point = 0;
    int count = 1;
    for (int i = 1; i < line_size; i++) {
        if (line[i - 1] == line[i]) {
            count++;
        }
        else {
            if (count >= 4) {
                for (int j = 1; j <= count; j++) {
                    point += line[i - j];
                    line[i - j] = 0;
                }
            }
            count = 1;
        }
    }
    if (count >= 4) {
        for (int j = 1; j <= count; j++) {
            point += line[line_size - j];
            line[line_size - j] = 0;
        }
    }
    ret += point;
    return point;
}

void remove_zero() {
    int back_size = 0;
    int back[2500] = { 0, };

    //0이 아닌 값들만 back에 복사
    for (int i = 0; i < line_size; i++) {
        if (line[i] != 0) {
            back[back_size++] = line[i];
        }
    }
    for (int i = 0; i < back_size; i++) {
        line[i] = back[i];
    }
    line_size = back_size;
}

void change_by_rule() {
    int back_size = 0;
    int back[2500] = { 0, };
    int count = 1;
    for (int i = 1; i < line_size; i++) {
        if (line[i - 1] == line[i]) {
            count++;
        }
        else {
            if (back_size < N * N - 2) {
                back[back_size++] = count;
                back[back_size++] = line[i - 1];
            }
            count = 1;
        }
    }
    if (line_size > 0 && back_size < N * N - 2) {
        back[back_size++] = count;
        back[back_size++] = line[line_size - 1];
    }
    for (int i = 0; i < back_size; i++) {
        line[i] = back[i];
    }
    line_size = back_size;
}

void convert_to_mat() {
    int ddy[] = { 0,1,0,-1 };
    int ddx[] = { -1,0,1,0 };

    int cy = N / 2;
    int cx = N / 2;
    int d = 0;
    int loop_count = 2;
    int cur = 0;
    for (int dist = 1; dist < N; dist++) {
        if (dist == N - 1) {
            loop_count = 3;
        }
        for (int i = 0; i < loop_count; i++) {
            for (int j = 0; j < dist; j++) {
                cy += ddy[d];
                cx += ddx[d];
                if (cur < line_size) {
                    mat[cy][cx] = line[cur++];
                }
                else {
                    mat[cy][cx] = 0;
                }
            }
            d = (d + 1) % 4;
        }
    }
}

int main() {

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> mat[y][x];
        }
    }

    ret = 0;
    for (int i = 0; i < M; i++) {
        int d, s;
        cin >> d >> s;
        destroy_by_rule(d-1, s); //index가 0부터이므로 -1
        convert_to_line();
        while (destroy_by_rule() != 0) {
            remove_zero();
        }
        remove_zero();
        change_by_rule();
        convert_to_mat();
    }

    cout << ret;

    return 0;
}