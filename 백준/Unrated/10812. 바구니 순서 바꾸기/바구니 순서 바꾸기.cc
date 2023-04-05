#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> A;
    for(int i=0;i<n;i++) {
        A.push_back(i+1);
    }

    int B[m][3];
    for(int i=0; i<m; i++) {
        cin>>B[i][0]>>B[i][1]>>B[i][2];
    }

    for(int i=0; i<m; i++) {
        rotate(A.begin()+B[i][0]-1, A.begin()+B[i][2]-1, A.begin()+B[i][1]); //종료 반복자에는 -1을 해주면 안됨
    }

    for(int i=0; i<n; i++) {
        cout<<A[i]<<' ';
    }


    

    return 0;
}