#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    if(n%2==1){
        int num = 1;
        while(n>=num){
            answer+=num;
            num+=2;
        }
    }
    else{
        int num=2;
        while(n>=num){
            answer+=(num*num);
            num+=2;
        }
    }
    
    return answer;
}