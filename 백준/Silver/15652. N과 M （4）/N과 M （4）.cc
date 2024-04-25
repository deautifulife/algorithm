#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visited[8];
int sequence[8];

void makesequence(int depth) {
    if(depth == m){
        for (int index = 0; index < m; index++) {
            cout << sequence[index] << ' ';
        }
        cout << '\n';
        return;
    }

    else {
        for (int index = 1; index <= n; index++) {
            if (index >= sequence[depth - 1]) {
                sequence[depth] = index;
                makesequence(depth + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    makesequence(0);

    return 0;
}
