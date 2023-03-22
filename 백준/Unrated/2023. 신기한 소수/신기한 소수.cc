#include <iostream>
using namespace std;

static int N; 
void DFS(int number, int jarisu);
bool isPrime(int number);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    DFS(2, 1); // 소수, 해당 소수의 자릿수
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);        
}

void DFS(int number, int jarisu) {
    if(jarisu == N) {
        if(isPrime(number)) { //소수면 출력
            cout << number << endl;
        }
        return;
    }
    for(int i=1; i<10;i++){
        if(i % 2 == 0)
            continue;
        if(isPrime(number*10+i)) {
            DFS(number * 10 + i, jarisu +1);
        }
    }
    
}

//소수 판별
bool isPrime(int number) {
    for(int i =2; i <= number /2; i++) {
        if(number%i == 0) return false;
    }
    return true;
}