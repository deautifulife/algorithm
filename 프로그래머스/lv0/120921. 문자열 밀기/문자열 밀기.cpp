#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    bool check = false;
    
    if(A==B)
        return 0;
    
    for(int i=0; i<A.size()-1; i++){
        char s=A[A.size()-1];
        A=A.substr(0, A.size()-1);
        A=s+A;
        
        answer++;
        
        if(A==B){
            check=true;
            break;
        }
    }
    if(check)
        return answer;
    else
        return -1;
    
    return answer;
}