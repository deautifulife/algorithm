#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    int finalIdx = s + overwrite_string.length();
    int idxCnt = 0;
    
    for(int i=0; i<my_string.length(); i++){
        if(i>=s && i<finalIdx){
            answer += overwrite_string[idxCnt++];
        }
        else{
            answer += my_string[i];
        }
    }
    
    return answer;
}