#include <iostream>

using namespace std;

int card[100];
int n,m;
int sum;
int ans;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    int min = 999999;

    for(int i=0; i<n; i++) {
        cin>>card[i];
    }

    for(int i=0; i<n-2; i++)
        for(int j=i+1; j<n-1; j++)
            for(int k=j+1; k<n; k++) {
                sum = card[i]+card[j]+card[k];
                if(m - sum < min && m - sum >= 0) { //3개합이 m보다 같거나 작아야하며, 차이가 제일 적은걸 구함
                    min = m - sum;
                    ans = sum;
                }
            }
    cout<<ans;

    return 0;

}
