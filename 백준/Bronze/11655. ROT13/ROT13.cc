#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string text;
    getline(cin, text);

    vector<char> answer;

    for(int i=0; i<text.length(); i++) {
        if(text[i]<='9')//숫자나 공백인 경우
            answer.push_back(text[i]); //그대로 넣기
        if(text[i]>='A' && text[i]<='Z') { //대문자인 경우
            if((int)text[i]+13>'Z') //13 밀었을 때 90보다 커지면
                answer.push_back((char)((int)text[i]-13));//13을 땡기기
            else                
                answer.push_back((char)((int)text[i]+13));//13밀기
        }
        if(text[i]>='a' && text[i]<='z') {//소문자인 경우
            if((int)text[i]+13>'z')
                answer.push_back((char)((int)text[i]-13));
            else
                answer.push_back((char)((int)text[i]+13));
        }
    }

    for(int i=0; i<answer.size(); i++) {
        cout<<answer[i];
    }
    

    return 0;
}