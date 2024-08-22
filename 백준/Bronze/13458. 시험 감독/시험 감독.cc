#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int testroom[1000001];
int n;
int b, c;
long long ret;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> testroom[i];
    }

    cin >> b >> c;

    for (int i = 0; i < n; i++) {
        testroom[i] -= b;
        ret++;
        if (testroom[i] > 0) {
            ret += testroom[i] / c;
            if (testroom[i] % c != 0)
                ret++;
        }
    }

    cout << ret;

}