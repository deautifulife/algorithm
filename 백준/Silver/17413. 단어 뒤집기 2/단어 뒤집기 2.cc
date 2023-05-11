#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void stackprint(stack<char> &stack){
    while(!stack.empty()){
        cout<<stack.top();
        stack.pop();
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> stack;
    string str;
    getline(cin, str);
    for(int i=0; i<str.length(); i++){
        if(str[i]=='<'){
            stackprint(stack);
            while(1){
                cout<<str[i];
                if(str[i]=='>')
                    break;
                i++;
            }
        }
        else if(str[i] == ' '){
            stackprint(stack);
            cout<<" ";
        }
        else{
            stack.push(str[i]);
        }
    }
    stackprint(stack);

	return 0;
}