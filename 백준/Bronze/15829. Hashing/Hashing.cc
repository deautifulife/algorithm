// 이거도 문제 서론이 더 어려웠음

#include <iostream>  
#include <string> 
#include <vector>
// #include <algorithm>

using namespace std;

int n;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    cin>>str;

    long long ret =0;
    long long  M = 1234567891;
    int r = 31;
    long long power = 1;
    for(int i=0; i<str.length(); i++){
        ret += ((str[i]-'a' +1) * power) % M; // 누적에도 mod M을 안해줘서 50점만 나왔다고한다.
        power = (power * r) % M;
    }

    cout<<ret % M;


    return 0; 
}