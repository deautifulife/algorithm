#include <iostream>
#include <cmath>

using namespace std;

string a, b;

int calMax(string str) {
	int result = 0;
	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i])) {
			int cmp = str[i] - 'a';
			cmp += 11; //최소 11진법 이상이라는 것
			result = max(result, cmp);
		}
		else {
			int cmp = str[i] - '0';
			cmp += 1;
			result = max(result, cmp);
		}
	}
	return result;
}

long long calculate(int num, string str) {
	long long result = 0;
	int tmp = 0;

	for (int i = str.size() - 1; i >= 0; i--) {
		int rem;
		if (isalpha(str[i])) {
			rem = str[i] - 'a';
			rem += 10;
		}
		else {
			rem = str[i] - '0';
		}
		result += pow(num, tmp) * rem;
		tmp += 1;
	}

	return result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	//그 수의 문자열에 따른 최소 진수 구하기
	int max_a = calMax(a);
	int max_b = calMax(b);

	int cnt = 0;
	long long answer, answer_a, answer_b;

	for (int i = max_a; i <= 36; i++) {
		for (int j = max_b; j <= 36; j++) {
			long long a_tmp = calculate(i, a);
			long long b_tmp = calculate(j, b);

			if (i == j) {
				continue;
			}
			if (a_tmp == b_tmp && a_tmp >= 0) {
				cnt += 1;
				answer = a_tmp;
				answer_a = i;
				answer_b = j;
			}
		}
	}

	if (cnt >= 2)
		cout << "Multiple";
	else if (cnt == 0)
		cout << "Impossible";
	else
		cout << answer << " " << answer_a << " " << answer_b;

	return 0;
}