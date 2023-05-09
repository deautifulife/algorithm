#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcase;
    stack<int> s;
    cin>>tcase;
    while(tcase--){
        string command;
        cin>>command;

        if(command == "push"){
            int n;
            cin>>n;
            s.push(n);
        }

        else if(command == "pop"){
            if(s.empty())
                cout<<-1<<'\n';
            else{
                cout<<s.top()<<'\n';
                s.pop();
            }
        }

        else if(command == "size"){
            cout<<s.size()<<'\n';
        }

        else if(command == "empty"){
            if(s.empty())
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }

        else if(command == "top"){
            if(s.empty())
                cout<<-1<<'\n';
            else
                cout<<s.top()<<'\n';
        }
    }


}