#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long ans;
long long m,n;
long long list[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>m>>n;
    long long maxl = 0;
    for(int i=0; i<n; i++){
        cin>>list[i];
        maxl = max(maxl, list[i]);
    }

    long long s = 1;
    long long e = maxl;
    long long mid;

    while(s<=e){
        //mid 재정의
        mid = (s+e)/2;

        //만들 수 있는 과자의 합 초기화
        long long sum = 0;

        for(int i=0; i<n; i++){
            sum += list[i]/mid;
        }
        //만들어진 과자 갯수가 m보다 같거나 크면, s를 오른쪽으로 더 움직여 길이가 더 길게 만들 수 있는지 확인
        if(sum>=m){
            s = mid+1;
            //m개이상으로 과자가 만들어질때마다 과자의길이가 큰걸로 갱신
            ans = max(ans,mid);
        }
        //n보다 작으면, e를 왼쪽으로 움직여 mid값을 낮추어 짧은 과자로 나눌 수 있도록 함
        else{
            e = mid -1;
        }

    }
    cout<<ans<<'\n';

    return 0;
}