#include <string>
#include <vector>

using namespace std;

int solution(string message) {
    int answer = message.length();
    // for(int i=0; i<message.length(); i++){
    //     if((message[i] >= 'A' && message[i] <= 'z') || message[i] == ' ' || message[i] == '!' || message[i] == '~')
    //         answer++;
    // }
    return answer * 2;
}