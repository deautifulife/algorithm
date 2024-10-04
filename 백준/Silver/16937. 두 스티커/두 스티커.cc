#include <iostream>

using namespace std;

int board[100][100];
int sticker_r[100];
int sticker_c[100];
int h, w;
int n;
int sum;
int mmax;

void cal() {
    //1번째 붙일 스티커 선택
    for (int i = 0; i < n - 1; i++) {
        //스티커 크기가 모눈종이에 붙일 수 있는지 체크
        if (!((h >= sticker_r[i] && w >= sticker_c[i]) || (h >= sticker_c[i] && w >= sticker_r[i])))
            continue;
        //2번째 붙일 스티커 선택
        for (int j = i + 1; j < n; j++) {
            if (!((h >= sticker_r[j] && w >= sticker_c[j]) || (h >= sticker_c[j] && w >= sticker_r[j])))
                continue;

            sum = 0;

            //1. i회전 x, j회전 x 세로로 붙이기
            if (sticker_r[i] + sticker_r[j] <= h && max(sticker_c[i], sticker_c[j]) <= w) {
                sum = sticker_r[i] * sticker_c[i] + sticker_r[j] * sticker_c[j];
            }
            //2. i회전 x, j회전 o 세로로 붙이기
            else if (sticker_r[i] + sticker_c[j] <= h && max(sticker_c[i], sticker_r[j]) <= w) {
                sum = sticker_r[i] * sticker_c[i] + sticker_r[j] * sticker_c[j];
            }
            //3. i회전 x, j회전 x 가로로 붙이기
            else if (max(sticker_r[i], sticker_r[j]) <= h && sticker_c[i] + sticker_c[j] <= w) {
                sum = sticker_r[i] * sticker_c[i] + sticker_r[j] * sticker_c[j];
            }
            //4. i회전 x, j회전 o 가로로 붙이기
            else if (max(sticker_r[i], sticker_c[j]) <= h && sticker_c[i] + sticker_r[j] <= w) {
                sum = sticker_r[i] * sticker_c[i] + sticker_r[j] * sticker_c[j];
            }
            //5. i회전 o j회전 x 세로로 붙이기
            else if (sticker_c[i] + sticker_r[j] <= h && max(sticker_r[i], sticker_c[j]) <= w) {
                sum = sticker_r[i] * sticker_c[i] + sticker_r[j] * sticker_c[j];
            }
            //6. i회전 o j회전 o 세로로 붙이기
            else if (sticker_c[i] + sticker_c[j] <= h && max(sticker_r[i], sticker_r[j]) <= w) {
                sum = sticker_r[i] * sticker_c[i] + sticker_r[j] * sticker_c[j];
            }
            //7. i회전 o j회전 x 가로로 붙이기
            else if (max(sticker_c[i], sticker_r[j]) <= h && sticker_r[i] + sticker_c[j] <= w) {
                sum = sticker_r[i] * sticker_c[i] + sticker_r[j] * sticker_c[j];
            }
            //8. i회전 o j회전 o 가로로 붙이기
            else if (max(sticker_c[i], sticker_c[j]) <= h && sticker_r[i] + sticker_r[j] <= w) {
                sum = sticker_r[i] * sticker_c[i] + sticker_r[j] * sticker_c[j];
            }

            mmax = max(mmax, sum);
        }
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sticker_r[i] >> sticker_c[i];
    }

    cal();
    cout << mmax;

    return 0;
}