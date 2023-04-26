#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string answer = "";
    char idx[my_string.length()];
    char temp;
    for(int i=0; i<my_string.length(); i++){
        idx[i] = my_string[i];
    }
    
    temp = idx[num1];
    idx[num1] = idx[num2];
    idx[num2] = temp;
    
    for(int i=0; i<my_string.length(); i++){
        answer.push_back(idx[i]);
    }
    
    return answer;
}