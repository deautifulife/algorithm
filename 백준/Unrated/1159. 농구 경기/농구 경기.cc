#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    string player;

    int alpha[26];
    for(int i=0; i<26; i++) {
        alpha[i] = 0;
    }

    //선수 성 저장
    for(int i=0; i<n; i++) {
        cin>>player;
        alpha[(int)player[0] - 97]++;
    }

    //알파벳 스캔
    vector<char> startingmember; 
    int cnt = 0;
    for(int i=0; i<26; i++) {
        if(alpha[i]>=5){
            startingmember.push_back((char)(i+97));
            cnt++;
        }
    }

    if(cnt>=1)
        for(int i=0; i<cnt; i++) {
            cout<<startingmember[i];
        }
    else
        cout<<"PREDAJA";
    

    return 0;
}