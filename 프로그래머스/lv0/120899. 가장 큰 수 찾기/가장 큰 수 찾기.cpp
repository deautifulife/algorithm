#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    stack<int> s;
    int idx=0;
    s.push(array[0]);
    for(int i=1; i<array.size(); i++){
        if(s.top()<array[i]){
            s.pop();
            s.push(array[i]);
            idx=i;
        }
    }
    answer.push_back(s.top());
    answer.push_back(idx);
    
    return answer;
}