#include<iostream>
#include <vector>
#include <string>
using namespace std;
int ans = 0;

//aabaa의 경우 a, aa, aab, aaba, aabaa 로 보는데 한글자인 a는 접두사,접미사가 같은걸로 보지 않음
// 따라서 i는 1부터 시작한다.
vector<int> makeTable(string p) {// 패턴문자의 접두사 접미사 구하기
	int psize = p.length();
	vector<int> table(psize, 0);
	int j = 0;
	for (int i = 1; i < p.size(); i++) {//1~m
		while (j > 0 && p[i] != p[j]) {
			j = table[j - 1];// 길이만큼 뛰어넘는다
		}
		if (p[i] == p[j]) {
			table[i] = ++j;
		}

	}
	
	return table;
}

void kmp(string s, string p) {
	vector<int> table = makeTable(p);//접미사, 접두사 길이 구하기
	int psize = p.size();
	int ssize = s.size();
	int j = 0;
	for (int i = 0; i < ssize; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = table[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == psize - 1) {//패턴길이가 3일때 j가 0,1,2가 같으면 3글자가 같으니 검사끝
				ans = 1;
				j = table[j];
				return;
			}
			else {
				j++;
			}
		}
	}

}

int main(int argc, char** argv)
{

	string s, p;
	cin >> s >> p;
	kmp(s, p);
	cout << ans << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}