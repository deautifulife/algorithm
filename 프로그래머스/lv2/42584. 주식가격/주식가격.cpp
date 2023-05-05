#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    stack<int> s;
    int size = prices.size();
    vector<int> answer(size);
    
    for(int i=0; i< size; i++){
        //스택이 비어있지 않고 스택 top값이 현재값보다 크면 -> 가격이 떨어졌다면
        while(!s.empty() && prices[s.top()]>prices[i]){
            //가격이 떨어졌으므로 i - s.top() 대입
            answer[s.top()] = i - s.top();
            s.pop(); //값 제거
        }
        s.push(i);
        
    }
    while(!s.empty()){
        answer[s.top()] = size - s.top() - 1; //인덱스는 0부터라서 -1해줘야함
        s.pop();
    }
    
    return answer;
}