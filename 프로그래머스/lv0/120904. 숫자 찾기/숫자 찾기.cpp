#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    string sNum = to_string(num);
    for(int i=0; i<sNum.length(); i++){
        if(sNum[i]-'0'==k){
            answer = i;
            break;
        }
        else
            answer = -2;
            
    }
    
    return answer+1;
}