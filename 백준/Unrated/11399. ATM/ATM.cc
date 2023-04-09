#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int,int>> A(n);

    for(int i=0; i<n; i++) {
        cin>>A[i].first; //걸리는 시간
        A[i].second = i; //번호
    }

    sort(A.begin(), A.end()); //걸리는 시간 빠른 순으로 정렬

    //계산
    int answer = 0;
    int time;
    for(int i=0; i<n; i++) {
        time = A[i].first;
        if(i>0) {
            A[i].first += A[i-1].first;
            time = A[i].first;
        }
            
        answer += time;
    }

    cout<<answer;

}
