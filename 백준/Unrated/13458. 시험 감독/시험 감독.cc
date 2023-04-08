#include <iostream>


using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,b,c;

    long long master=0; //총감독
    int ass = 0; //부감독
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
        master++; //시험장마다 총감독관 넣기
    }
    
    cin>>b>>c;
    for(int i=0; i<n; i++) {
            if(a[i]-b>0) {
                master += (a[i]-b)/c; //한 방의 학생수 중 총감독이 커버가능한 학생 수 제거하고 부감독관 넣기
                if((a[i]-b)%c) //나머지가 생기면 부감독 추가
                    master++;
            }
    }
    
    

    cout<<master;

    return 0;
}