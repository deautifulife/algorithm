#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    int answer = 0;
    
    answer = flag==1 ? a+b : a-b;
    return answer;
}