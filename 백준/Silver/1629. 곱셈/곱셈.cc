#include <iostream>
#include <vector>

using namespace std;

long long a,b,c;

long long pow(int a, int b, int c){
	if(b==0)
		return 1;
	long long temp = pow(a, b/2, c);
	temp = temp * temp % c;
	if(b%2 == 0)
		return temp; // 짝수일 때
	else
		return temp * a % c; //홀수일 때
}

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>a>>b>>c;
	cout<<pow(a,b,c);

}