#include <iostream>
#include <algorithm> //sort함수

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    sort(arr, arr+n); //sort(배열의 포인터, 배열의 포인터 + 배열의 크기)

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<'\n';
    }


    return 0;
}