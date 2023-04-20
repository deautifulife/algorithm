#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 1;
    while(k-1>0){
        answer += 2;
        if(answer > numbers.size()) {
            answer -= numbers.size();
        }
        k--;
    }
    
    
    return answer;
}