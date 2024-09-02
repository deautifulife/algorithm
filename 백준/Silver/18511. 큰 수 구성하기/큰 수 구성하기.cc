#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, k;
int ret = 0;
vector<int> v;

void dfs(int num, int ten) { //num : 주어진 k개의 종류 원소로 만들 수 있는 숫자, ten : 자릿수
    if (n < num) {
        return;
    }
    ret = max(ret, num);
    for (int i = 0; i < v.size(); i++) {
        dfs(num + v[i] * ten, ten * 10);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    dfs(0, 1);

    cout << ret;


    return 0;

}