#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b && a==c){
        cout<<10000+(a*1000)<<'\n';
    }
    if(a==b && a!=c) {
        cout<<1000+(a*100)<<'\n';
    }
    if(a==c && a!=b) {
        cout<<1000+(a*100)<<'\n';
    }
    if(b==c && b!=a) {
        cout<<1000+(b*100)<<'\n';
    }
    if(a!=b && a!=c && b!=c) {
        int max = a;
        if(max < b)
            max = b;
        if(max < c)
            max = c;
        cout<<max*100<<'\n';

    }

    return 0;
}