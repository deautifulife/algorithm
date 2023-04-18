#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int age) {
    string answer = "";
    while(1){
        if(age < 10){
            age= age%10;
            answer.push_back((char)(age%10 + 'a'));
            break;
        }    
        answer.push_back((char)(age%10 + 'a'));
        age = age/10;
               
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}