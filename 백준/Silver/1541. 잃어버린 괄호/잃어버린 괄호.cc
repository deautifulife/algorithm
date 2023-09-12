#include <iostream>
#include <string>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ret=0;
	string formula;
	string num;
	cin >> formula;

	bool isMinus = false;
	for (int i = 0; i <= formula.size(); i++) {
		if (formula[i] == '-' || formula[i] == '+' || i == formula.size()) {
			if (isMinus) {
				ret -= stoi(num);
				num = "";
			}
			else {
				ret += stoi(num);
				num = "";
			}
		}
		else {
			num += formula[i];
		}
		if (formula[i] == '-') {
			isMinus = true;
		}
	}
	cout << ret;

	return 0;
}