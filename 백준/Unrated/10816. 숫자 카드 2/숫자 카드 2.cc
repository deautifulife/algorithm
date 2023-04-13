#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n;
    vector<int> card(n);
    for(int i=0; i<n; i++){
        cin>>card[i];
    }

    sort(card.begin(), card.end());

    cin>>m;
    for(int i=0; i<m; i++) {
        int number;
        cin>>number;
        //upper_bound = 찾는값을 초과하는 값이 처음 나오는 인덱스 반환
        //lower_bound = 찾는값 이상값이 처음 나오는 인덱스 반환
        //upper_bound - lower_bound 값이 찾는값의 개수일 것이다.
        cout<<upper_bound(card.begin(), card.end(), number) - lower_bound(card.begin(), card.end(), number)<<" ";
    }
    return 0;
}
