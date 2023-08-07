#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;
int num;
double sum;
vector<int> order;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second == p2.second) //빈도수 같으면
        return p1.first < p2.first; //숫자 작은게 앞
    return p1.second > p2.second; //빈도수가 높은게 앞
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        sum += num;
        order.push_back(num);
    }

    //순서 정렬
    sort(order.begin(), order.end());

    //산술평균 출력
    //floor은 내림함수로 +0.5를 해주어 반올림처럼 쓴다.
    cout << (int)floor((sum / n) + 0.5) << '\n';

    //중앙값 출력
    cout << order[n / 2] << '\n';

    //최빈값 출력
    vector<pair<int, int>> v; //숫자와 빈도수를 저장할 벡터생성
    
    for (int i = 0; i < order.size(); i++) {
        if (v.empty()) {
            v.push_back(make_pair(order[i], 1));
            continue;
        }

        if (v.back().first == order[i]) {
            //v[i - 1].second++;
            pair<int, int> tmp = v.back();
            tmp.second++;
            v.pop_back();
            v.push_back(tmp);
        }

        else
            v.push_back(make_pair(order[i], 1));
    }

    //빈도수가 높고, 숫자가 낮은 순으로 정렬
    sort(v.begin(), v.end(), comp);

    //조건 : 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
    if (v[0].second == v[1].second)
        cout << v[1].first << '\n';
    else
        cout << v[0].first << '\n';

    //범위 출력
    cout << order.back() - order.front() << '\n';

    

    return 0;
}