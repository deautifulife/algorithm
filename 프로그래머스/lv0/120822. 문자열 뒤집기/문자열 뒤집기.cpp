#include <string>
#include <vector>
#include <algorithm> //reverse 함수를 쓰기 위함

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    reverse(my_string.begin(), my_string.end()); //reverse(시작배열,끝배열)
    
    answer = my_string;

    
    return answer;
}