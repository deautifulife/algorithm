#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    int alpha[26]; //알파벳 배열 생성

    //알파벳 배열 초기화
    for(int i=0; i<26; i++) {
        alpha[i] = 0;
    }

    //단어에서 알파벳 체크해서 알파벳 배열에 카운트
    for(int i=0; i<s.length(); i++) {
        alpha[(int)s[i]-97]++;
    }

    //알파벳 배열 출력
    for(int i=0; i<26; i++) {
        cout<<alpha[i]<<' ';
    }

    return 0;
}