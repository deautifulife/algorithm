#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,j;
    int cnt = 0;
    int front = 1;
    int back;
    int applePo;
    
    cin>>n>>m;
    back = m;
    cin>>j;
    for(int i=0; i<j; i++){
        cin>>applePo;
        //사과 담을 때 까지
        while(1) {
            if(front <= applePo && applePo <= back) //사과가 바구니 범위 안이면
                break;
            if(applePo < front){ //바구니보다 앞에 있으면
                front--;
                back--;
                cnt++;
            }
            if(applePo > back) { //바구니보다 뒤면
                front++;
                back++;
                cnt++;
            }
        
        }
    }
    cout<<cnt;

    return 0;

}
