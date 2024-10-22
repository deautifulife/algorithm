#include <iostream>
#include <algorithm>

using namespace std;

int rope[100000];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>rope[i];
    }

    //내림차순 정렬
    sort(rope, rope+n, greater<int>());

    int ans = 0;
    for(int i=0; i<n; i++){
        int sum = rope[i] * (i+1);
        if(sum > ans)
            ans = sum;
    }

    cout<<ans;
   

	return 0;
}