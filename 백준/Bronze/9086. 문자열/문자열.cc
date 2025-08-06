#include <iostream>  
#include <string>    
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin>>num;
    for(int i=0; i<num; i++){
        string str;
        cin>>str;
        cout<<str[0]<<str[str.length()-1]<<'\n';
    }

    return 0; 
}