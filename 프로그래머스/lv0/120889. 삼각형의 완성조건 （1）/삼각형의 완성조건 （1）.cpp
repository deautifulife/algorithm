#include <string>
#include <vector>
#include <algorithm> //sort 함수를 쓰기위함

using namespace std;

int solution(vector<int> sides) {
    int answer = 2;
    sort(sides.begin(), sides.end()); //오름차순으로 정렬
    if(sides[0]+sides[1]>sides[2])
        answer = 1;

    return answer;
}