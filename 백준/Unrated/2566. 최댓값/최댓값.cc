#include <iostream>

using namespace std;

int main() {
    
    int Max = -1; // max가 0이면 모두 0일때 문제가 생김
    int row,col = 0;
    int a[9][9];

    for(int i=0;i<9;i++) {
        for(int j=0; j<9; j++) {
            cin>>a[i][j];
        }
    }

    for(int i=0;i<9;i++) {
        for(int j=0; j<9; j++) {
            if(Max < a[i][j]) {
                Max = a[i][j];
                row = i;
                col = j;
            }
        }
    }


    cout<<Max<<'\n'<<row+1<<' '<<col+1<<'\n';

    return 0;
}