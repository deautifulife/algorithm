#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcase;
    cin>>tcase;
    while(tcase--){
        stack<char> s;
        string PS;
        cin>>PS;

        for(int i=0; i<PS.length(); i++){
            if(s.empty())
                s.push(PS[i]);

            else{
                if(PS[i]==')'){
                    if(s.top()=='(')
                        s.pop();
                    else
                        s.push(PS[i]);
                }
                else
                    s.push(PS[i]);
            }
        }

        if(s.empty())
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    

}