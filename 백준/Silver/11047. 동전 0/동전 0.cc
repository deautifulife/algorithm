#include <iostream>

using namespace std;

int n,k;
int coin[10];
int cnt;

int main() {

	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>coin[i];
	}

	for(int i=n-1; i>=0; i--){
		while(coin[i] <= k){
			k -= coin[i];
			cnt++;
		}
	}
	cout<<cnt;

	return 0;
	
}