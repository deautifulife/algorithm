#include <iostream>  
#include <string> 
#include <vector>
#include <algorithm> // reverse 함수

using namespace std;

vector<string> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        string n;
        cin>>n;
        if(n=="0")
            break;
        
        v.push_back(n);
    }

    for(int i=0; i<v.size(); i++){
        string rev = v[i];
        reverse(rev.begin(), rev.end()); // 문자열 뒤집기
        if(v[i] == rev)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }

    return 0; 
}