#include <string>
#include <vector>


using namespace std;

int solution(string before, string after) {
    int answer = 0;
    int b = 0;
    int a = 0;
    for(int i=0; i<before.length(); i++){
        b+= before[i]-'a';
    }
    for(int i=0; i<after.length(); i++){
        a+= after[i]-'a';
    }
    if(a==b)
        answer = 1;
    
    return answer;
}