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
    int total = 0;
    cin>>input;
    for(int i=0; i<input.length(); i++){
        if(input[i] == '('){
            st.push(input[i]);
        }
        //레이저면
        else if(input[i] == ')' && input[i-1]=='('){
            st.pop();
            total += st.size();
        }
        //마지막 자투리
        else{
            total++;
            st.pop();
        }
    }
    cout<<total<<'\n';
}