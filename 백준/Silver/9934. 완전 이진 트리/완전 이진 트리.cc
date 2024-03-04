#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int k;
int num;
int arr[1024];
vector<int> tree[10];

void solution(int s, int e, int d) {
    if (d >= k)
        return;

    if (s == e) { //리프 노드
        tree[d].push_back(arr[s]);
        return;
    }

    int m = (s + e) / 2;
    if (m < 0 || m >= num)
        return;

    tree[d].push_back(arr[m]); //중간 값 트리 내 depth에 push

    solution(s, m - 1, d + 1); //왼쪽 서브 트리
    solution(m + 1, e, d + 1); //오른쪽 서브 트리
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    num = pow(2, k) - 1;

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    solution(0, num - 1, 0);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            cout << tree[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
