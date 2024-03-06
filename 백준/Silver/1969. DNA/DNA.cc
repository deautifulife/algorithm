#include <iostream>
#include <vector>

using namespace std;

vector<string> v;

int n, m;
int ret = 0;
int CHD, NHD=9999;
vector<char> cret;
char alpha[4] = { 'A', 'C', 'G', 'T' }; //사전순

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	
	//입력 단계
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}


	//완전 탐색
	for (int i = 0; i < m; i++) { //자릿수 m
		NHD = 9999;
		char nchar = 'A';
		for (int d = 0; d < 4; d++) { //알파벳들
			CHD = 0;
			for (int j = 0; j < n; j++) { //각 s들
				if (v[j][i] != alpha[d]) {
					CHD++;
				}
			}
			if (CHD < NHD) {
				NHD = CHD;
				nchar = alpha[d];
			}
		}
		ret += NHD;
		cret.push_back(nchar);
	}

	for (int i = 0; i < m; i++) {
		cout << cret[i];
	}

	cout << '\n'<<ret;

	return 0;
}