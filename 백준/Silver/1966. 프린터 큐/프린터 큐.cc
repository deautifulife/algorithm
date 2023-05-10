#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tcase;
    cin>>tcase;
    int n, m, ipt; //문서 갯수, 찾는 문서, 중요도
    for(int i=0; i<tcase; i++){
        //m의 문서가 몇번째로 인쇄되는지 카운트
        int cnt=0;
        cin>>n>>m;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            cin>>ipt;
            q.push(make_pair(i, ipt)); ///인덱스와 중요도
            pq.push(ipt); //중요도가 높은 순으로
        }
        while(!q.empty()){
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            //우큐의 top과 중요도가 일치하면
            if(pq.top() == value){
                pq.pop();
                cnt++;
                //현재 문서의 인덱스가 m이면
                if(index == m){
                    cout<<cnt<<'\n';
                    break; //다음 테케로 넘어가기
                }
            }
            else
                //중요도가 높지 않으면 큐의 맨뒤에 다시 push
                q.push(make_pair(index,value));
        }
    }

}