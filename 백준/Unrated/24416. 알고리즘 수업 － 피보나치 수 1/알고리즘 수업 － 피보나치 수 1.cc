#include <iostream>

using namespace std;

int recur_cnt; //재귀 카운트
int dp_cnt;
int arr[44];

int fib(int a) {
    if(a==1 or a==2) {
        recur_cnt++;
        return 1;
    }
    else{
        return fib(a-1) + fib(a-2);
    }
}

void fibonacci(int b) {
    arr[1] = 1;
    arr[2] = 1;
    for (int i=3; i<=b; i++) {
        dp_cnt++;
        arr[i] = arr[i-1]+arr[i-2];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    fib(n);
    fibonacci(n);
    cout<<recur_cnt<<" "<<dp_cnt;
    
    
    return 0;

}
