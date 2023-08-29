#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	char left[3][5] = { {'q','w','e','r','t'} , {'a','s','d','f','g'}, {'z','x','c','v','.'} };
	char right[3][6] = { {'.','y','u','i','o','p'}, {'.','h','j','k','l','.'}, {'b','n','m','.','.','.'}};

	char a, b;
	string str;
	int apx,apy,bpx,bpy;
	int ans = 0;
	cin >> a >> b;
	cin >> str;

	bool acheck = 0, bcheck = 0;
	for (int i = 0; i < 3; i++) {
		if (acheck == 1 && bcheck == 1)
			break;
		for (int j = 0; j < 6; j++) {
			if (j<5 && a == left[i][j]) {
				apx = j;
				apy = i;
				acheck = 1;
			}
			if (b == right[i][j]) {
				bpx = j;
				bpy = i;
				bcheck = 1;
			}
		}
	}

	for (int i = 0; i < str.length(); i++) {
		bool strcheck = 0;
		for (int j = 0; j < 3; j++) {
			if (strcheck == 1)
				break;
			for (int k = 0; k < 6; k++) {
				if (k<5 && str[i] == left[j][k]) {
					ans += abs(apx - k) + abs(apy - j);
					apx = k;
					apy = j;
					strcheck = 1;
					break;
				}
				else if (str[i] == right[j][k]) {
					ans += abs(bpx - k) + abs(bpy - j);
					bpx = k;
					bpy = j;
					strcheck = 1;
					break;
				}
			}
		}
	}


	ans += str.length();
	cout << ans;


	return 0;
}