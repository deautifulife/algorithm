#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;
vector<string> v;

//check 0 = 회문 판단, check=1 : 유사회문 파단
int palindrome(string s, int check){
    int left, right; //투 포인터
    left = 0;
    right = s.length() - 1;

    while(left < right){
        //회문이 아닐때
        if(s[left] != s[right]){
            //유사회문인지 검증
            if(check == 0){
                int len = right - left; //길이
                //left인덱스를 제외하고 자른 string가 회문이던가 left 인덱스를 포함하고 자른 string이 회문일 때 유사회문이라고 판단.
                //둘 중 한 문자 잘라서 회문이 된다는 거니까
                if(palindrome(s.substr(left+1, len), 1) == 0 || palindrome(s.substr(left, len), 1)==0)
                    return 1; //유사회문일떄
                else
                    return 2; //아닐때
            }
            //유사회문으로 검증됐는데 또 다른 문자열이 나오면 더 이상 자를수 없으니 아닌것으로 판단
            else
                return 2;
        }
        left++;
        right--;
    }
    //위에 문제없이 끝까지 내려오면 회문임.
    return 0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        string s;
        cin>>s;
        cout<<palindrome(s, 0)<<'\n';
    }

	return 0;
}