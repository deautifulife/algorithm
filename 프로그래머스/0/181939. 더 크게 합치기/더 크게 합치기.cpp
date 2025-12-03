#include <string>
#include <vector>

using namespace std;


int solution(int a, int b) {
    int answer = 0;
    int ans1 = stoi(to_string(a) + to_string(b));
    int ans2 = stoi(to_string(b) + to_string(a));
    
    if(ans1 >= ans2)
        answer = ans1;
    else
        answer= ans2;
    
    
    return answer;
}