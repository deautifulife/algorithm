#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;
    
    //두 당 1조각씩 떨어질 때 까지 반복
    while(!(answer*slice/n>=1))
        answer++;
    
    return answer;
}