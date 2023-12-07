#include <iostream>

using namespace std;

int N,S;
int swit[101];

void trans(int num) {
	if (swit[num] == 0)
		swit[num] = 1;
	else if (swit[num] == 1)
		swit[num] = 0;
}

void command(int sex, int num) {
	if (sex == 1) {
		for (int i = num; i <= N; i += num) {
			trans(i);
		}
	}
	else if (sex == 2) {
		trans(num);
		int front = num - 1;
		int back = num + 1;
		while (1) {
			if (front <1 || back >N)
				break;
			if (swit[front] == swit[back]) {
				trans(front);
				trans(back);
				front--;
				back++;
				
			}
			else
				break;
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> swit[i];
	}
	cin >> S;
	for (int i = 0; i < S; i++) {
		int sex, num;
		cin >> sex >> num;
		command(sex, num);
	}

	for (int i = 1; i <= N; i++) {
		cout << swit[i] << ' ';
		if (i % 20 == 0) {
			cout << '\n';
		}

	}

	return 0;
}