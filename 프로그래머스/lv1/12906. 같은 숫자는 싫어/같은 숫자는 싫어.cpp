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
        //스택이 안비워져있고 스택 top이 현대 인덱스와 같은 값이라면 팝하고 마지막에 푸쉬해줌
        while(!s.empty() && s.top() == arr[i]){
            s.pop();
        }
        s.push(arr[i]);
    }
    //스택이 빌때까지 top값을 정답벡터에 넣고 팝을 반복
    while(!s.empty()){
        answer.push_back(s.top());
        s.pop();
    }

    return answer;
}