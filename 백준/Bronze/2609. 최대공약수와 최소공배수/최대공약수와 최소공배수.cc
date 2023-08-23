#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//유클리드 호제법
int Solvegcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return Solvegcd(b, a % b);
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	int gcd = Solvegcd(a, b);
	cout<< gcd <<'\n';
	cout << a * b / gcd; //최소공배수 = 두 자연수의 곱 / 최대공약수


	return 0;
}