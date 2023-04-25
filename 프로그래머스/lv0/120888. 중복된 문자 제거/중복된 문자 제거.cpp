#include <string>
#include <vector>

bool alpha[52];

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(int i=0; i<my_string.length(); i++){
        if(alpha[my_string[i]-'A']==0){
            answer.push_back(my_string[i]);
            alpha[my_string[i]-'A'] = 1;
        }
    }
    return answer;
}