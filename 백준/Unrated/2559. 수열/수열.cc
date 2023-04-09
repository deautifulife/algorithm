#include <iostream>


using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[100001];

    int n,k;
    cin>>n>>k;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int start = 0;
    int sum = 0;
    int max = -999999;

    for (int i=0; i<n; i++) {
        sum += arr[i];

        if(i >= k - 1) { // 
            if(max < sum)
                max = sum;
            sum -= arr[start++];
        }
    }

    cout << max;



}
