#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    int cnt = 0; 

    for (int h = 0; h <= n; h++) {
        for (int m = 0; m < 60; m++) {
            for (int s = 0; s < 60; s++) {
                if (h % 10 == k || h / 10 == k || m % 10 == k || m / 10 == k || s % 10 == k || s / 10 == k)
                    cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
    
}