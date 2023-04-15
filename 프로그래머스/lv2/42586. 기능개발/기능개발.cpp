#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int size = progresses.size();
    int day = 1;
    
    for(int i=0; i<size; i++){
        q.push(i);
    }
    
    while(!q.empty()){
        int cnt = 0;
        while(!q.empty() && 100-progresses[q.front()] <= speeds[q.front()]*day){
            cnt++;
            q.pop();
        }
        if(cnt != 0)
            answer.push_back(cnt);
        
        day++;
    }    
    
    
    return answer;
}