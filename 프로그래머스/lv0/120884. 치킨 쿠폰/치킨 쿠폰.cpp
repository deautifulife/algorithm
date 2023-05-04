#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = -1;
    int service = chicken/10;
    answer = service;
    int coupon = chicken%10 + service;
    
    while(coupon>=10){
        answer++;
        coupon-=10;
        coupon++;
    }
        
    
    return answer;
}