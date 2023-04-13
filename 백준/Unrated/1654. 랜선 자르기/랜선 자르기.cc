#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long ans;
long long n,k;
long long list[10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>k>>n;
    long long maxl = 0;
    for(int i=0; i<k; i++){
        cin>>list[i];
        maxl = max(maxl, list[i]);
    }

    long long s = 1;
    long long e = maxl;
    long long mid;

    while(s<=e){
        //mid 재정의
        mid = (s+e)/2;

        //만들 수 있는 랜선의 합 초기화
        long long sum = 0;

        for(int i=0; i<k; i++){
            sum += list[i]/mid;
        }
        //만들어진 랜선 갯수가 n보다 같거나 크면, s를 오른쪽으로 더 움직여 길이가 더 길게 만들 수 있는지 확인
        if(sum>=n){
            s = mid+1;
            //n개가 만들어질때마다 나누는 랜선의 값이 더 큰걸로 갱신
            ans = max(ans,mid);
        }
        //n보다 작으면, e를 왼쪽으로 움직여 mid값을 낮추어 짧은 랜선으로 나눌 수 있도록
        else{
            e = mid -1;
        }

    }
    cout<<ans<<'\n';

    return 0;
}