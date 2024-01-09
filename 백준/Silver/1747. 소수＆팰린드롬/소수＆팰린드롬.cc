#include <iostream>

using namespace std;

bool isPrime(long long num) {
	if (num <= 1)
		return false;
	if (num == 2 || num == 3)
		return true;
	if (num % 2 == 0 || num % 3 == 0)
		return false;
	for (long long i = 5; i * i <= num; i++) {
		if (num % i == 0 || num % (i + 2) == 0)
			return false;
	}
	return true;
}

bool is_palindrome(long long num) {
	long long num_original = num;
	long long num_rev = 0;
	while (num > 0) {
		num_rev = num_rev * 10 + num % 10;
		num /= 10;
	}

	return num_original == num_rev;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;
	while (1) {
		while (!isPrime(N)) {
			N++;
		}
		if (N < 10) {
			cout << N;
			break;
		}

		else if (is_palindrome(N) == true) {
			cout<<N;
			break;
		}
		N++;

	}
	


	return 0;
}