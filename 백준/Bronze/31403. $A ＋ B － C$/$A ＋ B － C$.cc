#include <iostream>  
#include <string> 

using namespace std;

int a,b,c;

int resStr(int a, int b, int c){
    if(b==1000){
        a *= 10000;
    }
    else if(b>=100){
        a *= 1000;
    }
    else if(b>=10){
        a *= 100;
    }
    else
        a *=10;

    return a+b-c;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin>>a>>b>>c;

    int resNum = a+b-c;

    cout<<resNum<<'\n';
    cout<<resStr(a,b,c);

    return 0; 
}