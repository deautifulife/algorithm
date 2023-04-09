#include <iostream>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h,w;
    cin>>h>>w;
    int answer[h][w];
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            char weather;
            cin>>weather;
            if(weather=='c') {
                answer[i][j] = 0;                
            }
            else
                answer[i][j] = -1;
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(answer[i][j] != 0) {
                if(j>0 && answer[i][j-1]>=0)
                    answer[i][j]=answer[i][j-1]+1;
            }
            cout<<answer[i][j]<<' ';
        }
        cout<<'\n';
    }

}