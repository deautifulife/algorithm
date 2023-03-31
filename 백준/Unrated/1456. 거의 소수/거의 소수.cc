#include <iostream>
#include <vector>
#include <cmath> // 제곱근 연산

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long Min, Max;
    cin >> Min >> Max;
    long A[10000001];
    
    //소수 구하기
    for(int i=2; i<10000001; i++) {
        A[i] = i;
    }
    
    for(int i=2; i<= sqrt(10000001); i++) { //제곱근까지만 계산
        if(A[i] == 0) {
            continue;
        }
        for(int j= i+i; j< 10000001; j= j+i) {
            A[j] = 0; //i의 배수면 0으로 바꿈
        }
    }
    int count = 0;
    
    //거의소수 구하기
    for(int i=2; i<10000001; i++) {
        if(A[i]!=0) { //소수면
            long temp = A[i];
            while((double)A[i] <= (double)Max/(double)temp) {
                if((double)A[i] >= (double)Min/(double)temp) {
                    count++;
                }
                temp = temp * A[i];
            }
        }
    }
    cout << count << endl;
}