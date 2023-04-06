#include <iostream>

using namespace std;

int main() {
    
    int n;
    int cnt=0; //소수 카운트
    cin>>n;
    int max = 0;
    int arr[n];
    for(int i=0; i<n;i++) {
        cin>>arr[i];
        if(max<arr[i])
            max = arr[i];
    }

    // if(max==1){
    // cout<<0<<endl;
    // return 0;
    // }

    // 나누어 줄 수(소수인 2부터 n개중의 max값까지)
    for(int i=1; i<=max; i++) {
        if(i==1)
            continue;
        //배열 탐색하면서 나눠준다
        for(int j=0; j<n; j++) {
            if(arr[j]==1){
                arr[j]=-1;
                continue;
            }
            if(arr[j]==-1){
                continue;
            }
            if(arr[j]==i) {
                continue;
            }

            if(arr[j]%i==0){
                arr[j]=-1;
            }
        }
    }

    //소수 카운트
    for(int i=0; i<n; i++) {
        if(arr[i]!= -1)
            cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}