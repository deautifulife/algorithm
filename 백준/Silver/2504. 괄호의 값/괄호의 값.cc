#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> st;
    string input;
    cin>>input;

    int ans=0, temp= 1;

    for(int i=0; i<input.length(); i++){
        // temp에 2or3을 곱하고 스택에 push
        if(input[i] == '('){
            temp *= 2;
            st.push(input[i]);
        }
        else if(input[i] == '['){
            temp *= 3;
            st.push(input[i]);
        }
        else if(input[i] == ')'){
            if(st.empty() || st.top() != '(') {
                ans = 0;
                break;
            }
            if(input[i-1] == '(') {
                ans += temp;
                temp /= 2;
                st.pop();
            }
            else{
                temp /= 2;
                st.pop();
            }
        }
        else if(input[i] == ']'){
            if(st.empty() || st.top() != '[') {
                ans = 0;
                break;
            }
            if(input[i-1] == '[') {
                ans += temp;
                temp /= 3;
                st.pop();
            }
            else{
                temp /= 3;
                st.pop();
            }
        }
    }
    if(!st.empty())
        ans = 0;
    cout<<ans<<'\n';

}