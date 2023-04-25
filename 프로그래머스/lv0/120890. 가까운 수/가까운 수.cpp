#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 101;
    int a,b;
    for(int i=0; i<array.size(); i++){
        a = n-array[i];
        if(a<0)
            a*=-1;
        b = n-answer;
        if(b<0)
            b*=-1;
        if(a<b)
            answer = array[i];
        if(a==b)
            answer = min(answer, array[i]);
    }
    return answer;
}