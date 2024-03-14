#include <iostream>
#include <vector>
using namespace std;

int n;
int ret = 99999999;
vector<pair<int,int>> material;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        material.push_back(make_pair(a,b));
    }

    for(int i=1; i<(1<<n); i++){ //1(00..001)부터 2^n-1(11..111)까지 (n자리수)
        int sour=1, bitter=0;
        for(int x=0; x<n; x++){ //최대 n-1칸 shiftleft
            if(i&(1<<x)){ //조건문 결과가 1이면 해당 재료 사용한 것 
                sour *= material[x].first;
                bitter += material[x].second;
            }
        }
        ret = min(ret, abs(sour-bitter));
    }

    cout<<ret;

	return 0;
}