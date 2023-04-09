#include <iostream>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;
    int n = 1;
    cin>>a>>b>>c;
    if(c-b<1) {
        cout<<-1;
        return 0;
    }
    
    cout<<a/(c-b) +1<<endl;

}