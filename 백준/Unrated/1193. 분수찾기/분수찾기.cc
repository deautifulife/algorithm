#include <iostream>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin>>x;

    //x가 몇번째 라인에 있는지 확인
    int line = 1;
    while(x>line) {
        x = x-line;
        line++;
    }

    //결과로 나온 값은 line번째 대각선의 x번째 있음
    if(line%2==1)  //line이 홀수면
        cout<<line-x+1<<"/"<<x<<'\n';
    else
        cout<<x<<"/"<<line-x+1<<'\n';

}