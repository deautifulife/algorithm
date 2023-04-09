#include <iostream>
#include <string>

using namespace std;

bool check_vowel(char c);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    while(1) {
        string test;
        bool pass = false;
        int con =0;
        int vol = 0; //자음 모음 카운트
        cin>>test;

        if(test.compare("end") == 0) { //같으면 0 다르면 -1을 리턴함
            break;
        }
        //조건 1 : a,e,i,o,u 1개 무조건 포함
        for(int i=0; i<test.length(); i++) {
            if(check_vowel(test[i]))
                pass = true;
        }
        if(pass != true) {
            cout<<"<"<<test<<">"<<" "<<"is"<<" "<<"not"<<" "<<"acceptable."<<'\n';
            continue;
        }
        
        //조건 2 : 자음or모음 연속 3개 x
        for(int i=0; i<test.length(); i++) {
            if(pass==false)
                break;
            if(check_vowel(test[i])) { //모음이면 모음 카운트 올리고 자음 카운트 초기화d
                vol++;
                con = 0;
            }
            else { //위와 반대
                con++;
                vol = 0;
            }
            if(vol == 3 || con == 3) {//조건 2에서 벗어나면
                pass = false;
                continue;
            }  
            //조건3 같은 글자 연속이면, 단, e,o는 아닐 때
            if(i>0 && test[i] == test[i-1] && !(test[i]=='e' || test[i]=='o')) {
                pass = false;
            }
        }
        if(pass != true)
            cout<<"<"<<test<<">"<<" "<<"is"<<" "<<"not"<<" "<<"acceptable."<<'\n';
        else
            cout<<"<"<<test<<">"<<" "<<"is"<<" "<<"acceptable."<<'\n';     
    }
        
}

bool check_vowel(char c) {
    if( c== 'a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
    return false;
}