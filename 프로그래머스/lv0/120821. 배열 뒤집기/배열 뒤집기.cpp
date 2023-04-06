#include <string>
#include <vector>
#include <algorithm> // reverse 함수를 쓰기 위함

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    reverse(num_list.begin(), num_list.end()); //벡터 시작 반복자부터 끝 반복자까지 뒤집기
    
    answer = num_list;
    
    return answer;
}