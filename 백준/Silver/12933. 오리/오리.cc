#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> ducks;

bool Solution(char word, char key, int num) {
	if (word == key) {
		for (int i = 0; i < ducks.size(); i++) {
			if (ducks[i].length() % 5 == num) {
				ducks[i].push_back(word);
				return false;
			}
		}
	}
	if (word == 'q' && key == 'q') {
		ducks.push_back("q");
		return false;
	}
	return true;
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	bool fail; //녹음 실패 변수
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		fail = true;
		char word = str[i]; //현 위치의 비교 변수
		//ducks 벡터가 비었으면
		if (ducks.empty()) {
			if (word == 'q') {
				ducks.push_back("q");
				fail = false;
			}
		}
		//하나라도 0이면 fail은 0이 된다.
		else {
			fail &= Solution(word, 'q', 0); //0번째 문자열의 word가 q인지 비교
			fail &= Solution(word, 'u', 1);
			fail &= Solution(word, 'a', 2);
			fail &= Solution(word, 'c', 3);
			fail &= Solution(word, 'k', 4);
		}

		if (fail)
			break;
	}
	
	for (int i = 0; i < ducks.size(); i++) {
		//quack 완성이 안된 벡터가 있는 경우 녹음 실패
		if (ducks[i].length() % 5 != 0) {
			cout << "-1";
			return 0;
		}
	}
	if (fail)
		cout << "-1";
	else
		cout << ducks.size();

	return 0;
}