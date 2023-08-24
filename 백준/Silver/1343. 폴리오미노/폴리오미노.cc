#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string board, ans;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int cnt=0;
	cin >> board;

	for (int i = 0; i < board.length(); i++) {
		if (board[i] == 'X')
			cnt++;
		if (board[i] == '.') {
			ans += ".";
			if (cnt % 2 != 0) {
				cout <<"-1";
				return 0;
			}
			else
				cnt = 0;
		}

		if (cnt == 2 && board[i + 1] != 'X') {
			ans += "BB";
			cnt = 0;
		}
		else if (cnt == 4) {
			ans += "AAAA";
			cnt = 0;
		}
	}

	//.없이 X가 홀수로 끝날 떄
	if (cnt % 2 == 1)
		cout << "-1";
	else
		cout << ans;

	return 0;
}