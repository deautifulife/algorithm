#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    deque<int> d;
    int tcase;
    cin>>tcase;
    while(tcase--){
        string comm;
        cin>>comm;

        if(comm == "push_front"){
            int n;
            cin>>n;
            d.push_front(n);
        }

        else if(comm == "push_back"){
            int n;
            cin>>n;
            d.push_back(n);
        }

        else if(comm == "pop_front"){
            if(d.empty())
                cout<<-1<<'\n';
            else{
                cout<<d.front()<<'\n';
                d.pop_front();
            }
        }

        else if(comm == "pop_back"){
            if(d.empty())
                cout<<-1<<'\n';
            else{
                cout<<d.back()<<'\n';
                d.pop_back();
            }
        }

        else if(comm == "size"){
            cout<<d.size()<<'\n';
        }

        else if(comm == "empty"){
            if(d.empty())
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }

        else if(comm == "front"){
            if(d.empty())
                cout<<-1<<'\n';
            else
                cout<<d.front()<<'\n';
        }

        else if(comm == "back"){
            if(d.empty())
                cout<<-1<<'\n';
            else
                cout<<d.back()<<'\n';
        }
    }
}