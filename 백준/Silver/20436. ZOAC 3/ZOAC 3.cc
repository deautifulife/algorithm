#include <iostream>
#include <cmath>

using namespace std;

char sl, sr;
int ll, lr;
char arr[101];
int ret;

char za[3][6] = { {'q','w','e','r','t','*'}, {'a','s','d','f','g','*'}, {'z','x','c','v','*','*'}};
char mo[3][6] = { {'*','y','u','i','o','p'}, {'*','h','j','k','l','*'}, {'b','n','m','*','*','*'}};
bool zamo = false; //0이면 자음 1이면 모음

int find_coor(char alpha) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			if (za[y][x] == alpha) {
				zamo = 0;
				return y * 10 + x;

			}
			else if(mo[y][x] == alpha) {
				zamo = 1;
				return y * 10 + x;
			}
		}
	}
}

void click(char alpha) {
	int coor = find_coor(alpha);
	//0이면 자음 1이면 모음
	if (zamo == 0) {
		ret += abs((coor / 10) - (ll / 10)) + abs((coor % 10) - (ll % 10));
		ll = coor;
	}
	else if (zamo == 1) {
		ret += abs((coor / 10) - (lr / 10)) + abs((coor % 10) - (lr % 10));
		lr = coor;
	}
	ret++; //클릭하는데 1초
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> sl >> sr;
	ll = find_coor(sl);
	lr = find_coor(sr);

	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		arr[i] = str[i];
		click(str[i]);
	}

	cout << ret;

	return 0;
}