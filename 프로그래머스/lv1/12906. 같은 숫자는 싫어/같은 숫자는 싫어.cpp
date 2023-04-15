#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> s;
    
    for(int i= arr.size()-1; i>=0; i--){
        while(!s.empty() && s.top() == arr[i]){
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty()){
        answer.push_back(s.top());
        s.pop();
    }

    return answer;
}