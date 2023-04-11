#include <iostream>

using namespace std;

int n,k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin>>n>>k;

    int pascal_arr[n][k];

    //삼각형에서 맨 첫째 인덱스의 값은 1로 고정
    for(int i=0; i<n; i++)
        pascal_arr[i][0] = 1;

    for(int i=1; i<n; i++){
        for(int j=1; j<=i; j++) { //i줄의 인덱스는 i개이므로
            if(j>=k)
                continue; //k 이상의 값을 구할 필요는 없다.
            //(n,k) = (n-1,k-1) + (n-1,k)에서 (n-1,k-1)을 일단 대입해놓는다.
            pascal_arr[i][j] = pascal_arr[i-1][j-1];

            //인덱스가 0부터 이므로 j의 최댓값은 i-1
            if(j<=i-1) //오른쪽 위가 없을때
                pascal_arr[i][j] += pascal_arr[i-1][j]; //(n-1,k)
        }
    }
    
    cout<<pascal_arr[n-1][k-1]; //인덱스가 0부터라서 각각 -1


    return 0;

}
