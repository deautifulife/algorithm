#include <iostream>

using namespace std;

long long dp[101];
int n;
long long ans[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    
    int t;
    cin>>t;
    for(int i=0; i<t; i++) {
        cin>>n;
        for(int j=4; j<=n; j++) {
            dp[j] = dp[j-3] + dp[j-2];
        }
        ans[i] = dp[n];
    }

    for(int i=0; i<t; i++){
        cout<<ans[i]<<'\n';
    }
    

    
    return 0;

}
