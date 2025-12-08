#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    bool mode = 0;
    
    for(int i=0; i<code.length(); i++){
        if(code[i] == '1'){
            mode= (mode+1)%2;
        }
        else{
            if(mode==0){
                if(i%2==0)
                    answer+=code[i];
            }
            else if(mode==1){
                if(i%2==1)
                    answer+=code[i];
            }
        }
    }
    
    if(answer == "")
        answer = "EMPTY";
    
    return answer;
}