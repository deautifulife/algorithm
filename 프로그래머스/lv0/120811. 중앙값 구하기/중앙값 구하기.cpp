#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    //sort(배열의 시작점 주소, 배열의 마지막 주소 +1)
    //벡터의 경우 아래와 같이
    sort(array.begin(), array.end());
    answer = array[array.size()/2];
    
    return answer;
}