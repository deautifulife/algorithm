#include <iostream>
#include <string>

using namespace std;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string eight;
	string two[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
	int temp;

	cin >> eight;

	for (int i = 0; i < eight.length(); i++) {
		temp = eight[i] - '0';
		//맨 앞 숫자가 0으로 시작하는 경우만 예외처리 해준다.
		if (i == 0)
			cout << stoi(two[temp]);
		else
			cout << two[temp];
	}
	
}