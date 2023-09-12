#include <iostream>

using namespace std;

int n, m;
int map[503][503];

//블록 종류 19개 4x4 + 종료문자 1
const char block[19][4][5] = {
	//일자
	{
		"1111",
		"0000",
		"0000",
		"0000" 
	},
	{
		"1000",
		"1000",
		"1000",
		"1000"
	},

	//ㅁ 자
	{
		"1100",
		"1100",
		"0000",
		"0000"
	},
	//ㄴ자
	{
		"1000",
		"1000",
		"1100",
		"0000"
	},
	{
		"1110",
		"1000",
		"0000",
		"0000"
	},
	{
		"1100",
		"0100",
		"0100",
		"0000"
	},
	{
		"0010",
		"1110",
		"0000",
		"0000"
	},
	{
		"0100",
		"0100",
		"1100",
		"0000"
	},
	{
		"1000",
		"1110",
		"0000",
		"0000"
	},
	{
		"1100",
		"1000",
		"1000",
		"0000"
	},
	{
		"1110",
		"0010",
		"0000",
		"0000"
	},
	//ㅇ
	//ㅇㅇ
	//  ㅇ  모양
	{
		"1000",
		"1100",
		"0100",
		"0000"
	},
	{
		"0110",
		"1100",
		"0000",
		"0000"
	},
	{
		"0100",
		"1100",
		"1000",
		"0000"
	},
	{
		"1100",
		"0110",
		"0000",
		"0000"
	},

	//ㅗ모양
	{
		"1110",
		"0100",
		"0000",
		"0000"
	},
	{
		"0100",
		"1100",
		"0100",
		"0000"
	},
	{
		"0100",
		"1110",
		"0000",
		"0000"
	},
	{
		"1000",
		"1100",
		"1000",
		"0000"
	},

};

//좌표, 블록 종류
int get_count(int sy, int sx, int k) {
	int ret = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			ret += (block[k][y][x] - '0') * map[sy + y][sx + x];
		}
	}
	return ret;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	//보드 채우기
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
		}
	}

	//보드 오른쪽, 아래쪽 +3칸에 -100000만 추가
	for (int y = n; y < n + 3; y++) {
		for (int x = 0; x < m + 3; x++) {
			map[y][x] = -100000;
		}
	}
	for (int y = 0; y < n + 3; y++) {
		for (int x = m; x < m + 3; x++) {
			map[y][x] = -100000;
		}
	}
	int ans = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			for (int k = 0; k < 19; k++) {
				int candi = get_count(y, x, k);
				if (ans < candi) {
					ans = candi;
				}
			}
		}
	}

	cout << ans<<'\n';

	return 0;
}