#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int> sum(n+1);
    sum[0] = 0;

    //누적 합 저장
    for(int i=1; i<=n; i++) {
        int num;
        cin>>num;
        sum[i] = sum[i-1] + num;
    }

    //계산
    for(int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<'\n';
    }

}
