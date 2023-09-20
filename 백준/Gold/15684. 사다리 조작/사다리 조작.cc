#include <iostream>

using namespace std;

int n, m, h, ret;
int map[31][11];

//사다리타기
bool check() {
	bool ret = true;

	for (int i = 1; i <= n; i++) {
		int pos = i;

		for (int j = 0; j <= h; j++) {
			//오른쪽 사다리
			if (map[j][pos] == 1) {
				pos++;
			}
			//왼쪽사다리
			else if (map[j][pos - 1] == 1) {
				pos--;
			}
		}

		if (pos != i) {
			return ret = false;
		}
	}

	return ret;
}

void dfs(int count, int y, int x) {
	//카운트가 이미 내가 찾은 결과보다 크거나 같으면 더 이상 체크할 필요가없음
	if (count >= ret)
		return;
	if (check()) {
		ret = count;
		return;
	}
	//선은 최대 3개
	if (count == 3)
		return;
	
	for (int i = y; i <= h; i++) {
		for (int j = x; j < n; j++) { //맨 마지막 세로선에서 선을 그으면 범위를 벗어나므로 <
			if (map[i][j] == 0 && map[i][j-1] ==0 && map[i][j+1] ==0) {
				map[i][j] = 1;
				dfs(count + 1, i, j);
				map[i][j] = 0; //백트래킹
			}
		}
		x = 1; //다음 y좌표에서 처음부터 선을 그을 수 있도록 1로 갱신
	}
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> h;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}

	ret = 4;
	dfs(0, 1, 1); //선그은 횟수, 시작점 좌표 2개
	
	//추가하는 선이 없었다면
	if (ret == 4)
		ret = -1;
	cout << ret;

	return 0;
} 