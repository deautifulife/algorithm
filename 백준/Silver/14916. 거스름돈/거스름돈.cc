#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int five = n / 5;
	if (n % 5 == 0) {
		cout << five;
		return 0;
	}
	while (five >= 0) {
		int result = (n - (five * 5)) % 2; //n에서 5원으로 나누고 남은 나머지가 2로 나눠지는가를 확인
		int two = (n - (five * 5)) / 2;
		if (result == 0) {
			cout << five + two;
			return 0;
		}
		five--;
	}
	cout << -1;

	return 0;
}