#include <iostream>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char gear[4][9]; //8이 아닌 9인 이유는 string 마지막 null문자 때문
	for (int i = 0; i < 4; i++) {
		cin >> gear[i];
	}
	int k;
	cin >> k;
	while (k--) {
		int target, cmd;
		cin >> target >> cmd;
		target--; //0부터 시작하므로
		int move_cmd[4] = { 0, };
		move_cmd[target] = cmd;
		//인접한 톱니바퀴들 회전
		for (int left = target - 1; left >= 0; left--) {
			int right = left + 1;
			if (gear[left][2] == gear[right][6]) {
				break;
			}
			else {
				move_cmd[left] = move_cmd[right] * -1;
			}
		}

		for (int right = target + 1; right < 4; right++) {
			int left = right - 1;
			if (gear[left][2] == gear[right][6]) {
				break;
			}
			else {
				move_cmd[right] = move_cmd[left] * -1;
			}
		}

		for (int i = 0; i < 4; i++) {
			//시계 방향
			if (move_cmd[i] == 1) {
				char temp = gear[i][7];
				for (int j = 7; j >= 1; j--) {
					gear[i][j] = gear[i][j - 1];
				}
				gear[i][0] = temp;
			}
			//반시계
			else if (move_cmd[i] == -1) {
				char temp = gear[i][0];
				for (int j = 0; j < 7; j++) {
					gear[i][j] = gear[i][j + 1];
				}
				gear[i][7] = temp;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == '1') {
			ret += (1 << i); //1,2,4,8
		}
	}
	cout << ret;

	return 0;
}