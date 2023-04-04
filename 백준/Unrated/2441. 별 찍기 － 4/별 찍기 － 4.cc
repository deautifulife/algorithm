#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int k=0;
        while(k<i){
            cout<<' ';
            k++;
        }
        for(int j=n-i; j>0; j--){
            cout<<"*";
        }
        cout<<'\n';
    }
    return 0;
}