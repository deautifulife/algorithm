#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string t;
int n;
int tChar[26];
int selectedChar[26];
pair<int, string> book[16];
int ret = 99999999;

bool check() {
    for (int i = 0; i < 26; i++) {
        if (tChar[i] > selectedChar[i]) {
            return false;
        }
    }
    return true;
}

void combination(int cnt, int priceSum) {
    if (cnt == n) {
        if (check()) {
            ret = min(ret, priceSum);
        }
        return;
    }

    for (int i = 0; i < book[cnt].second.length(); i++) {
        selectedChar[book[cnt].second[i] - 'A']++;
    }
    combination(cnt + 1, priceSum + book[cnt].first); //이번책+다음책1개의 경우
    //백트래킹
    for (int i = 0; i < book[cnt].second.length(); i++) {
        selectedChar[book[cnt].second[i] - 'A']--;
    }
    combination(cnt + 1, priceSum); //다음 책 단품의 경우
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> n;
    for (int i = 0; i < t.length(); i++) {
        tChar[t[i] - 'A']++;
    }
    for (int i = 0; i < n; i++) {
        cin >> book[i].first >> book[i].second;
    }

    combination(0, 0);

    if (ret == 99999999) {
        cout << -1;
    }
    else {
        cout << ret;
    }

    return 0;
}