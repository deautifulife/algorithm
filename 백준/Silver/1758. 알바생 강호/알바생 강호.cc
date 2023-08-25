#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int grade[100002];
vector<int> grade;

bool compare(int a, int b) {
	return a > b;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long sum = 0; //등수가 100000까지 이므로 범위가 늘어야함
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		grade.push_back(input);
	}

	sort(grade.begin(), grade.end(), compare);

	for (int i = 0; i < grade.size(); i++) {
		long long tip = grade[i] - (i);
		if (tip < 0)
			tip = 0;
		sum += tip;
	}
	cout << sum;


	return 0;
}