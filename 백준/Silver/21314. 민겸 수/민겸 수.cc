#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

string str;

string find_max() {
	stack<char> st;
	int M = 0;
	int K = 0;
	int ans = 0;
	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		//첫자리의 경우
		if (st.empty()) {
			if (str[i] == 'K') {
				ret += to_string(5);
			}
			else if (str[i] == 'M') {
				st.push(str[i]);
			}
		}
		else {
			if (st.top() == 'M' && str[i] == 'K') {
				ret += to_string(5);
				for (int i = 0; i < st.size(); i++) {
					ret += to_string(0);
				}
				while (!st.empty()) {
					st.pop();
				}
			}
			else {
				st.push(str[i]);
			}
		}
	}
	//뒤에 남은 m들은 최댓값이기에 m을 1로 바꿔서 더해줘야한다.
	if (!st.empty()) {
		for (int i = 0; i < st.size(); i++) {
			ret += to_string(1);
		}
	}
	
	return ret;
}

string find_min() {
	vector<char> M;
	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		//앞에 있는 M들은 10^M으로 변환한 후, 5를 더해준다.
		if (str[i] == 'K') {
			if (!M.empty()) {
				ret += to_string(1);
				for (int i = 0; i < M.size() - 1; i++) { //1을 빼주는건 맨앞에 1이 있으므로
					ret += to_string(0);
				}
				ret += to_string(5);
				M.clear();
			}
			else if (M.empty()) {
				ret += to_string(5);
			}
		}
		else if (str[i] == 'M') {
			M.push_back('M');
		}
	}

	//마찬가지로 뒤에 남은 M들을 10^M으로 변환해야 최솟값이다.
	if (!M.empty()) {
		ret += to_string(1);
		for (int i = 0; i < M.size() - 1; i++) {
			ret += to_string(0);
		}
	}
	return ret;
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> str;
	cout << find_max() << '\n';
	cout << find_min();


	return 0;
}