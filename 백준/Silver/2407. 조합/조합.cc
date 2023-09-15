#include <iostream>

using namespace std;

int n, m;
string arr[105][105]; //long long 범위를 벗어나는 값이 있으므로 string 형으로 큰 수 덧셈, 메모제이션

string add(string num1, string num2) {
	string num = "";
	int sum = 0;
	int size = max(num1.size(), num2.size());

	for (int i = 0; i < size || sum; i++) {
		if (num1.size() > i)
			sum += num1[i] - '0';
		if (num2.size() > i)
			sum += num2[i] - '0';

		num += sum % 10 + '0';
		sum /= 10;
	}

	return num;
}

string combi(int n, int m) {
	if (n == m || m == 0)
		return "1";

	string& ans = arr[n][m]; //참조형 변수
	if (ans != "")
		return ans;

	ans = add(combi(n - 1, m - 1), combi(n - 1, m));

	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	combi(n, m);
	for (int i = arr[n][m].size() - 1; i >=0; i--) {
		cout << arr[n][m][i];
	}

	return 0;
}