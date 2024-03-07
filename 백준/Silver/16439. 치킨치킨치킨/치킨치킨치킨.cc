#include <iostream>

using namespace std;

int prefer[30][30];
int pick[3];
int n,m;
int ret;

void combination(int idx, int cnt){
    if(cnt != -1){
        pick[cnt] = idx;
    }
    if(cnt ==2){
        int sum = 0;
        for(int i=0; i<n; i++){
            int score = 0;
            for(int j=0; j<3; j++){
                score = max(prefer[i][pick[j]], score);
            }
            sum += score;
        }
        ret = max(sum,ret);
        return;
    }
    for(int i= idx; i<m; i++){
        combination(i+1, cnt +1);
    }
}
int main(){

    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>prefer[i][j];
        }
    }

    combination(-1,-1);
    cout<<ret;

    return 0;
}