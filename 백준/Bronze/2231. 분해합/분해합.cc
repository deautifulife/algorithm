#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int ans=0;
    cin>>n;
    for(int i=1; i<=n; i++) {
        int result =0;
        int num = i;
        result = num;
        while(1) {
            if(num<10){
                result+=num;
                break;
            }
            result+=num%10;
            num=num/10;
        }

        if(result==n){
            ans = i;
            break;
        }
    }
    cout<<ans;

    return 0;

}