#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(int i=0; i<my_string.length(); i++){
        if(my_string[i]<'A'){
            answer += my_string[i]-'0';
        }
    }
    return answer;
}