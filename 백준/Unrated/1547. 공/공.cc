#include <iostream>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cup[3] = {1,2,3};
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        swap(cup[a-1],cup[b-1]);
    }

    for(int i=0; i<3; i++) {
        if(cup[i]==1)
            cout<<i+1;
    }
}

void swap(int a, int b){
    int temp;
    temp = b;
    b = a;
    a = temp;
}