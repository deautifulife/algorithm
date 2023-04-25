#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(int i=0; i<my_string.length(); i++){
        if(my_string[i] >= 'a')
            answer.push_back(my_string[i]-32);
        else
            answer.push_back(my_string[i]+32);
    }
    return answer;
}