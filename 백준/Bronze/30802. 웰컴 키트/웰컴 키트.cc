#include <iostream>  
#include <string> 
#include <vector>

using namespace std;

long long n; //참가자 수
vector <long long> Vsize;
// long long s,m,l,xl,xxl,xxxl; //사이즈별 신청자 수
long long t,p;

long long resTsh;
long long resPen1;
long long resPen2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=0; i<6; i++){
        long long n;
        cin>>n;
        Vsize.push_back(n);
    }
    cin>>t>>p;

    long long cnt = 0; // int 형으로 선언했다가 정신차리고 바꿈
    for(int i=0; i<6; i++){
        // 0인 경우를 생각못해서 틀렸음
        if(Vsize[i] == 0){
            continue;
        }
        else if(Vsize[i] <= t){
            cnt += 1;
        }
        else if(Vsize[i] % t == 0){
            cnt += Vsize[i]/t;
        }
        else{
            cnt += Vsize[i]/t + 1;
        }
    }
    
    resTsh = cnt;


    // 펜
    resPen1 = n/p;
    resPen2 = n%p;

    cout<<resTsh<<'\n';
    cout<<resPen1<<' '<<resPen2;

    return 0; 
}