#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<string> ducks;

bool Solution(char word, char key, int num) { //입력받은 문자, 기준 문자, 기준 문자길이
	//입력받은 문자 == 기준문자
	if (word == key) {
		//벡터 안에 있는 모든 문자열을 순차탐색하여 기준 문자길이 num과 같은 문자열이 있다면
		//그 문자열에 word를 추가하고 false를 반환한 후 끝
		for (int i = 0; i < ducks.size(); i++) {
			if (ducks[i].length() % 5 == num) {
				ducks[i].push_back(word);
				return false;
			}
		}
	}
	//for문을 빠져나왔다는 것은 모든 문자열을 돌았는데 num과 일치하는 문자열이 없다는 뜻
	//해당 오리들로는 해당 소리를 표현할 수 없다는 의미이므로 해당 문자가 'q'일 때만 새로운 문자열을
	//벡터에 추가한다.
	if (word == 'q' && key == 'q') {
		ducks.push_back("q");
		return false;
	}

	//그렇지 않은 경우는 true를 반환
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	bool fail;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		fail = true; //불가능한 상태인지 체크
		char word = str[i];
		if (ducks.empty()) {
			if (word == 'q') {
				ducks.push_back("q");
				fail = false;
			}
		}
		else {
			//&= : AND 비트연산자. 하나라도 0이면 0이 된다.
			fail &= Solution(word, 'q', 0);
			fail &= Solution(word, 'u', 1);
			fail &= Solution(word, 'a', 2);
			fail &= Solution(word, 'c', 3);
			fail &= Solution(word, 'k', 4);
		}

		if (fail)
			break;
	}

	//마지막에 반복문으로 한 번 더 문자열을 전부 체크해주는 이유
	//위에 것 만으로는 qqqqq같이 q만 들어올 때는 fail = true로 체크할 수 없기 때문
	for (int i = 0; i < ducks.size(); i++) {
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