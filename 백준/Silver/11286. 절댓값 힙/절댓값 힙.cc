#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b; //오름차순 (음수가 앞)
        }
        else{
            return abs(a) > abs(b); //절댓값크기 오름차 순
        }
    }
};

int n,x;
priority_queue<int, vector<int>, compare> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x==0){
            if(!pq.empty()){
                cout<<pq.top()<<'\n'; //front가 아님.
                pq.pop(); 
            }
            else cout<<0<<'\n';
        }
        else pq.push(x);
    }
    return 0;
}