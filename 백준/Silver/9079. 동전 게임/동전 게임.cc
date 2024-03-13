#include <iostream>
#include <queue>

using namespace std;

//2진수 비트로 만들기
int makeBit(string s) {
	int bit = 0;
	for (int i = 8; i >= 0; i--) {
		bit <<= 1;
		if (s[i] == 'H')
			bit |= 1;
	}
	return bit;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string coin;
		bool used[512] = { false, };
		int answer = -1;

		for (int i = 0; i < 9; i++) {
			char ch;
			cin >> ch;
			coin += ch;
		}

		int bit = makeBit(coin);

		queue<int> q;
		q.push(bit);
		used[bit] = true;

		bool flag = true;
		while (!q.empty() && flag) {
			int qsize = q.size();
			answer++;
			while (qsize--) {
				int cur = q.front();
				q.pop();
				if (cur == 0 || cur == (1 << 9) - 1) { //다 같은 면
					flag = false;
					break;
				}
				for (int nxt : {7, 56, 448, 73, 146, 292, 273, 84}) { //동전 뒤집는 8가지 방법
					int nxtState = cur ^ nxt; //xor연산 : 1이 하나일 때만 1을 반환
					if (used[nxtState]) //이미 이러한 면이 나온적 있으면
						continue;
					used[nxtState] = true;
					q.push(nxtState);
				}
			}
		}
		if (flag)
			answer = -1;
		cout << answer << '\n';
	}

	return 0;
}

