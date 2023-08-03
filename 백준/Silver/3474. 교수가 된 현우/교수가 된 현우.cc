#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	
	for(int i=0; i<t; i++){
		int n;
		cin>>n;

		int two =0, five =0;
		for(int j=2; j<=n; j*=2)
			two += n/j;
		for(int j=5; j<=n; j*=5)
			five += n/j;

		cout<<min(two,five)<<'\n';
	}

	
}