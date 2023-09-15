#include <iostream>

using namespace std;

int n, l, ret = 0;
int map[200][100];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}

	//맵 회전한 후 이어 붙이기(세로 계산 편하게 하기위해)
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			map[n + y][x] = map[x][y];
		}
	}

	int count = 0;

	int i, j; //for문이 끝까지 돌았는지를 체크하기위해 밖으로 뺌 
	for (i = 0; i < 2 * n; i++) {
		count = 1; //초기값은 1
		for (j = 0; j < n - 1; j++) { //현재값과 다음값을 비교하므로 1칸 적게
			//평지면
			if (map[i][j] == map[i][j + 1]) {
				count++;
			}
			//카운트가 l보다 커서 경사로를 놓을 수 있으면서 오르막인 경우
			else if (map[i][j] + 1 == map[i][j + 1] && count >= l) {
				count = 1; //카운트 초기화
			}
			//내리막
			else if (map[i][j] - 1 == map[i][j + 1] && count >= 0) {
				count = (1 - l);
			}
			else {
				break;
			}
		}
		//끝까지 나온 경우
		if (j == (n - 1) && count >= 0) {
			ret++;
		}
	}
	cout << ret;

	return 0;
}