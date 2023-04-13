#include <iostream>

using namespace std;

int house[1001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    int cost[3];
    for(int i=1; i<=n; i++) {
        cin>>cost[0]>>cost[1]>>cost[2];
        //r로 칠할 경우
        house[i][0] = min(house[i-1][1], house[i-1][2]) + cost[0];
        //g로 칠할 경우
        house[i][1] = min(house[i-1][0], house[i-1][2]) + cost[1];
        //b
        house[i][2] = min(house[i-1][0], house[i-1][1]) + cost[2];
    }
    cout<<min(house[n][0], min(house[n][1], house[n][2]));

    
    return 0;

}
