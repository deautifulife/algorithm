#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int num;
    deque<pair<int,int>> dq;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        //덱에 이동해야할 수와 풍선번호 저장
        dq.push_back(make_pair(num, i+1));
    }
    while(!dq.empty()){
        int cur = dq.front().first;
        cout<<dq.front().second<<" ";
        dq.pop_front();

        if(dq.empty()) //덱이 비었는데 연산을하면 에러가 나므로 break
            break;

        //양수면 이미 출력 후 pop을 한 번 했기 때문에 cur-1번만 front를 back로 옮김
        if(cur > 0){
            for(int i=0; i<cur-1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            //음수면 왼쪽 이동이므로 맨뒤의 값을 맨 앞으로 옮긴다.
            for(int i=0; i<cur*-1; i++){
                    dq.push_front(dq.back());
                    dq.pop_back();
            }
        }
    }

}