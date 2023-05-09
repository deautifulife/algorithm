#include <iostream>
#include <vector>

using namespace std;

int factorial(int n){
    if(n>2)
        n*=factorial(n-1);
    return n;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, ans =1;
    cin>>num;
    if(num!=0)
        ans = factorial(num);
    cout<<ans;
    

}