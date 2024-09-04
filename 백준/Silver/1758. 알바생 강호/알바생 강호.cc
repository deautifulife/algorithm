#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> line;
long long ret;

bool compare(int a, int b) {
    return a > b;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        line.push_back(p);
    }

    sort(line.begin(), line.end(), compare);

    for (int i = 0; i < n; i++) {
        int tip = line[i] - i;
        if (tip < 0)
            continue;
        ret += tip;
    }

    cout << ret;


    return 0;
}