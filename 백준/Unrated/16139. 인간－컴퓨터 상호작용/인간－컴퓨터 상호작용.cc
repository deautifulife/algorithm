#include <iostream>

using namespace std;

int psum[26][200000] = {0, }; //[알파벳][인덱스]

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin>> str;
    int q,l,r;
    char a;
    
    //문자열 각각 알파벳 수 카운트
    for(int i=0; i<str.length(); i++) {
        psum[str[i] - 'a'][i+1]++;
    }

    for(int i = 1; i<=str.length(); i++) {
        for(int j=0; j<26; j++){
            psum[j][i] += psum[j][i-1];
        }
    }

    cin>>q;
    for(int i=0; i<q; i++) {
        cin>>a>>l>>r;
        cout<<psum[a - 'a'][r+1]-psum[a - 'a'][l]<<'\n';
    }

}
