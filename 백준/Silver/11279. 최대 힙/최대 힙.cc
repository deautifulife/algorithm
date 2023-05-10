#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    priority_queue<int> pq;

    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x==0){
            if(pq.empty()) cout<<0<<'\n'; //큐가 비었으면 0출력
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }
}