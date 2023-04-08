#include <iostream>
#include <stack> // stack 사용 라이브러리

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int goodwords = 0;
    

    for(int i=0; i<n; i++) {
        stack<char> stack; // 스택선언 for문 돌때마다 초기화하기 위해 for문안에 선언
        string words;
        cin>>words;
        for(int j=0; j<words.length(); j++) {
            if(stack.empty()) //스택이 비었으면
                stack.push(words[j]); //단어 삽입
            else
                if(words[j]==stack.top()) //지금 단어가 스택 맨위 단어와 같으면
                    stack.pop(); //짝지어서 팡!
                else    
                    stack.push(words[j]); //단어 삽입
        }
        if(stack.empty()) //스택이 비어있으면
            goodwords++;    //좋은 단어
    }

    cout<<goodwords;

    return 0;
}