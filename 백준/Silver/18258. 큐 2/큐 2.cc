#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcase;
    cin>>tcase;
    queue<int> q;
    while(tcase--){
        string command;
        cin>>command;

        if(command =="push"){
            int n;
            cin>>n;
            q.push(n);
        }

        else if(command =="pop"){
            if(q.empty()){
                cout<<-1<<'\n';
                continue;
            }

            cout<<q.front()<<'\n';
            q.pop();
        }

        else if(command =="size"){
            cout<<q.size()<<'\n';
        }
        
        else if(command =="empty"){
            if(q.empty())
                cout<<1<<'\n';
            else
                cout<<0<<'\n';       
        }

        else if(command =="front"){
            if(q.empty()){
                cout<<-1<<'\n';
                continue;
            }

            cout<<q.front()<<'\n';
        }

        else if(command =="back"){
            if(q.empty()){
                cout<<-1<<'\n';
                continue;
            }

            cout<<q.back()<<'\n';
        }
    }
    

}