#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, m; //피로도,일처리,휴식,번아웃지점
	int fatigue = 0;
	int time = 24;
	int work = 0;
	cin >> a >> b >> c >> m;

	while (time > 0) {
		if (a + fatigue > m) {
			fatigue -= c;
			if (fatigue <= 0)
				fatigue = 0;
		}
		else {
			work += b;
			fatigue += a;
		}
		time--;
	}

	cout << work;

	return 0;
}