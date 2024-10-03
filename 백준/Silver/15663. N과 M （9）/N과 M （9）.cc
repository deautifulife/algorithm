#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[9];
int sequence[9];
bool visited[9];

void makesequence(int depth) {
    if (depth == m) {
        for (int index = 0; index < m; index++) {
            cout << sequence[index] << ' ';
        }
        cout << '\n';
        return;
    }

    else {
        int lastnum = 0;
        for (int index = 0; index < n; index++) {
            //오름차순으로 백트래킹 dfs를 돌리기 때문에 바로 앞 수열이랑 비교해서 중복을 막을 수 있다.
            if (visited[index] == false && lastnum != num[index]) {
                visited[index] = true;
                lastnum = num[index];
                sequence[depth] = num[index];
                makesequence(depth + 1);
                visited[index] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);

    makesequence(0);

    return 0;
}