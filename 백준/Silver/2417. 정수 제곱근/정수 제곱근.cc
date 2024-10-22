#include <iostream>
#include <math.h>

using namespace std;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    long long n,q;
    cin>>n;

    q = sqrt(n);

    if((q*q) < n){
        q++;
    }

    cout<<q;
   

	return 0;
}