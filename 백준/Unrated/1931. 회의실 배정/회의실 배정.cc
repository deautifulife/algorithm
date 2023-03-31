#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    
    for(int i=0; i<N; i++) { //종료시간이 우선순위가 높음 (정렬할 때)
        cin>>A[i].second; //시작시간
        cin>>A[i].first; //종료시간
    }
    
    sort(A.begin(), A.end()); //종료시간이 빠른애로 정렬이 됨
    
    int count = 0;
    int end = -1;
    
    for(int i=0; i<N; i++) { //회의 탐색
        if(A[i].second >= end) { //회의 시작시간이 종료시간보다 더 크면 = 안겹치면
            end = A[i].first;
            count++;
        }
    }
    cout << count << endl;
}