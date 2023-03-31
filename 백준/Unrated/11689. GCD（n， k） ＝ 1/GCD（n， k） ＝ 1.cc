#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long n;
    cin >> n;
    long result = n;
    
    // 소인수 분해를 해보면 n제곱근보다 큰 소인수는 1개만 나오거나 안나옴
    for(long p = 2; p<=sqrt(n); p++) {
        if(n%p == 0) { //소인수면
            result = result - result/p;
            // p에 관련된 소인수 제거
            while(n%p == 0) {
                n = n/p;
            }
        }
    }
    if(n>1) { //n이 마지막 소인수일 때
        result = result - result /n;
    }
    cout<<result<<endl;
}