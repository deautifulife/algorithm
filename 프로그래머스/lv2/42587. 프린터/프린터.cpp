#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    int size = priorities.size();
    int cnt = 1;
    
    for(int i=0; i<=size; i++){
        q.push(make_pair(priorities[i], i));
    }
    
    sort(priorities.begin(), priorities.end());
    
    for(int i=size-1; i>=0; i--){
        while(!q.empty()){
            if(q.front().first == priorities[i]){
                if(q.front().second == location){
                    answer = cnt;
                }
                q.pop();
                cnt++;
                break;
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }    
    }
    return answer;
}