#include <iostream>

using namespace std;

int dp[10000001];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1] = 1;
    dp[2] = 2;
    cin>>n;
    //점화식
    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%15746;
    }

    cout<<dp[n]<<'\n';

    
    return 0;

}
