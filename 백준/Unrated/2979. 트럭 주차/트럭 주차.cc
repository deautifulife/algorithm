#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int park[101];
    for(int i=0; i<101; i++) {
        park[i] = 0;
    }

    int a,b,c;
    cin>>a>>b>>c;

    int cnt = 0;
    int s,e;
    int max = 0; // 시간복잡도를 줄이기 위해 정산에서 탐색하는 배열의 수를 줄이기 위함
    int pay = 0; // 요금

    //주차
    while(cnt<3) {
        cin>>s>>e;
        if(max<e)
            max = e;

        for(int i=s; i<e; i++) {
            park[i]++;
        }
        cnt++;
   }

    //정산
    for(int i=0; i<max; i++) {
        if(park[i]==1)
            pay = pay + (park[i]*a);
        if(park[i]==2)
            pay = pay + (park[i]*b);
        if(park[i]==3)
            pay = pay + (park[i]*c);
    }

    cout<<pay<<'\n';

    return 0;
}