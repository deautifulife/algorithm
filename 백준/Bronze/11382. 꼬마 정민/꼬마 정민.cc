#include <iostream>  // 입출력을 위한 헤더 (cout 사용)
using namespace std;

int main(void) {

    long long a,b,c; // 범위가 10^12까지이므로 int로는 택도없다.

    cin>>a>>b>>c;
    cout<<a+b+c;

    return 0;
}
