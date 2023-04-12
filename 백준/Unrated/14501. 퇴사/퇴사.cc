#include <iostream>

using namespace std;

int n;
int t[17];
int p[17];
int dp[17];

void solution(){
    int max_pay = 0; //최댓값
    for(int i=0; i<=n; i++){
        dp[i] = max(max_pay, dp[i]);
        //퇴사하기전에 가능한 일정만
        if(t[i] + i <= n){
            dp[t[i] + i] = max(dp[t[i]+i], p[i]+dp[i]);
        }
        max_pay = max(max_pay, dp[i]);
    }
    cout<<max_pay;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>t[i]>>p[i];
    }

    solution();
    
    return 0;

}
