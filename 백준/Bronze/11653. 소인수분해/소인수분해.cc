#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int primefactor = 2;
	cin >> n;
	while (n != 1) {
		if (n % primefactor == 0) {
			n = n / primefactor;
			cout << primefactor << '\n';
		}
		else
			primefactor++;
	}

	return 0;
}