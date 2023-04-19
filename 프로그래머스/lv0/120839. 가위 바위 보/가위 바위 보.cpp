#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    for(int i=0; i<rsp.length(); i++){
        if(rsp[i]=='2')
            answer.push_back('0');
        else if(rsp[i]=='0')
            answer.push_back('5');
        else
            answer.push_back('2');
    }
    return answer;
}