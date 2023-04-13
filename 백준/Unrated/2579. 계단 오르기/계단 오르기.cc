#include <iostream>

using namespace std;

int step[302];
int dp[302];

int MaxPoint(int n){
    dp[1]=step[1];
    dp[2]=dp[1]+step[2];
    for(int i=3; i<=n; i++){
        dp[i]=max(dp[i-3]+step[i-1]+step[i] , dp[i-2]+step[i]);
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>step[i];
    }

    cout<<MaxPoint(n);
    
    return 0;

}
