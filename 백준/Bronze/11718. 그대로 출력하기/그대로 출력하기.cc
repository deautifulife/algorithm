#include <iostream>  // 표준 입출력을 위한 헤더
#include <string>    // 문자열(string) 사용을 위한 헤더
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;  

    // getline(cin, line): 표준 입력으로부터 한 줄을 읽어서 line에 저장
    // EOF (입력 끝)까지 계속 반복
    while (getline(cin, line)) {
        cout << line << '\n';  
    }

    return 0; 
}