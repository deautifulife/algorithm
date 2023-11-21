#include <iostream>

using namespace std;

bool student[30];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 28; i++) {
		int temp;
		cin >> temp;
		student[temp-1] = true;
	}

	for (int i = 0; i < 30; i++) {
		if (student[i] != true) {
			cout << i + 1<<'\n';
		}
	}
}