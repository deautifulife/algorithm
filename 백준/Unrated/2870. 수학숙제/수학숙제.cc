#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
string s,ret;
vector<string> v;

void zero() {
    while(1){
    if(ret.length() && ret.front()=='0') // 맨 앞이 0이면 삭제
        ret.erase(ret.begin());
    else
        break;
    }

    if(ret.length() == 0) //앞에서 0다 지워서 ret에 든게 없으면 ex)000
        ret = "0";

    v.push_back(ret);
    ret = "";
}

bool compare(string a, string b) {
    if(a.length() == b.length()) //글자 수 같으면
        return a < b; //맞으면 1 아니면 0 반환
    return a.length() < b.length(); //맞으면 1 아니면 0 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        ret = "";
        for(int j=0; j<s.length(); j++){
            if(s[j] < 'a') //글자가 숫자면
                ret += s[j];
            else if(ret.length()) //알파벳이 나왔고 ret에 글자이 있는 경우?
                zero(); //앞에 붙은 0 삭제.
        }
        if(ret.length()) //단어 다 넣었는데 ret에 값이 있다면
            zero();
    }

    sort(v.begin(), v.end(), compare); //compare가 맞으면 정렬 아니면 x

    for(string a : v)
        cout<<a<<'\n';

    return 0;
}