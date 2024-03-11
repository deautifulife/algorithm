#include <iostream>
#include <vector>

using namespace std;

int board[100][100];
//vector<pair<int, int>> v;
int sticker_r[100];
int sticker_c[100];
int h, w;
int n;
int sum;
int mmax;

void cal(int idx) {
    for (int i = 0; i < n - 1; i++) {
        if (!((h >= sticker_r[i] && w >= sticker_c[i]) || (h >= sticker_c[i] && w >= sticker_r[i])))
            continue;
        for (int j = i + 1; j < n; j++) {
            if (!((h >= sticker_r[j] && w >= sticker_c[j]) || (h >= sticker_c[j] && w >= sticker_r[j])))
                continue;

            sum = 0;

            //1. i회전 x, j회전 x 세로로 붙이기
            if (sticker_r[i] + sticker_r[j] <= h && max(sticker_c[i] , sticker_c[j]) <= w) {
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
        /*int r, c;
        cin >> r >> c;
        if ((h >= r && w >= c) || (h >= c && w >= r)) {
            v.push_back(make_pair(r, c));
        }*/
    }

    cal(0);
    cout << mmax;

    return 0;
}